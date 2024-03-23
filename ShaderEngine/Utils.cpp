#include "pch.h"
#include "Utils.h"
#include <regex>
#include <ShaderConductor/ShaderConductor.hpp>

std::string ShaderEngineUtils::ResolveShaderIncludes(std::string source, std::vector<std::string> include_paths, std::vector<std::string> resolved_includes)
{
    static const std::regex includeRegex(R"(#include\s+["<](.+)[">])");

    std::smatch match;
    std::string processedSource = "";
    processedSource.append(source);

    auto begin = std::sregex_iterator(source.begin(), source.end(), includeRegex);
    auto end = std::sregex_iterator();

    for (std::sregex_iterator i = begin; i != end; ++i) {
        match = *i;
        std::string includePath_str = match[1].str();

        std::filesystem::path include_path = includePath_str;

        std::string opening_Comment = "\n //----RESOLVED INCLUDE OF ";
        opening_Comment.append(includePath_str).append("---- \n");

        bool alreadyResolved = false;

        if (std::find(resolved_includes.begin(), resolved_includes.end(), includePath_str) != resolved_includes.end()) {
            alreadyResolved = true;
            size_t pos = processedSource.find(match[0].str());
            if (pos != std::string::npos) {
                processedSource.replace(pos, match[0].str().length(), "");
            }
        }

        if (processedSource.find(opening_Comment) == std::string::npos && !alreadyResolved) {

            std::string includedContent;
            std::string final_include_path;
            for (size_t i = 0; i < include_paths.size(); i++)
            {
                includedContent = read_bytes(include_paths[i] + "/" + includePath_str);
                if (!includedContent.empty()) 
                {
                    final_include_path = include_paths[i] + "/" + include_path.remove_filename().string();
                    final_include_path.pop_back();
                    break;
                }
            }
            include_paths.push_back(final_include_path);
            includedContent = ResolveShaderIncludes(includedContent, include_paths, resolved_includes);


            size_t pos = processedSource.find(match[0].str());
            if (pos != std::string::npos) {
                processedSource.replace(pos, match[0].str().length(), includedContent);
                processedSource.append(opening_Comment);
                resolved_includes.push_back(includePath_str);
            }
        }
    }

    return processedSource;
}

const void* ShaderEngineUtils::CompileHLSLToSPIRV(std::string source_unprocessed, std::vector<std::string> includes_dir, std::string entryPoint, ShaderConductor::ShaderStage stage, std::string filename)
{
    std::string source_processed = ResolveShaderIncludes(source_unprocessed, includes_dir, {});

    ShaderConductor::Compiler::Options options;
    options.optimizationLevel = 3;

    ShaderConductor::Compiler::TargetDesc targetDesc;
    targetDesc.language = ShaderConductor::ShadingLanguage::SpirV;
    targetDesc.version = "spirv1.4";

    ShaderConductor::Compiler::SourceDesc sourceDesc;
    sourceDesc.source = source_processed.c_str();
    sourceDesc.entryPoint = entryPoint.c_str();
    sourceDesc.stage = stage;
    sourceDesc.fileName = filename.c_str();

    std::vector<ShaderConductor::MacroDefine> defines;
#ifdef RELEASE
    defines.push_back({ "RELEASE", "1" });
#endif
#ifdef DEBUG
    defines.push_back({ "DEBUG", "1" });
#endif

    sourceDesc.defines = defines.data();
    sourceDesc.numDefines = static_cast<uint32_t>(defines.size());

    ShaderConductor::Compiler::ResultDesc result = ShaderConductor::Compiler::Compile(sourceDesc, options, targetDesc);

    if (result.hasError)
    {
        std::string err_txt = "Shader compilation error: ";
        err_txt.append(reinterpret_cast<const char*>(result.errorWarningMsg.Data()));
        LP_CORE_ERROR(err_txt);
        return nullptr;
    }
    else 
    {
        return result.target.Data();
    }
}
