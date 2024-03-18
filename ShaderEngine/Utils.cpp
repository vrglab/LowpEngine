#include "pch.h"
#include "Utils.h"
#include <regex>

LP_Extern LP_API std::string ResolveShaderIncludes(std::string source, std::string directoryPath)
{
    static const std::regex includeRegex(R"(#include\s + '(.+)')");
    std::smatch match;
    std::string processedSource = source;

    auto begin = std::sregex_iterator(source.begin(), source.end(), includeRegex);
    auto end = std::sregex_iterator();

    for (std::sregex_iterator i = begin; i != end; ++i) {
        match = *i;
        std::string includePath = match[1].str();
        std::string fullPath = directoryPath + "/" + includePath;

        std::string opening_Comment = "//----RESOLVED INCLUDE OF ";
        opening_Comment.append(includePath).append("----");

        if (processedSource.find(opening_Comment) == std::string::npos) {
            uint32_t* size;
            std::string includedContent = read_bytes(fullPath, size);

            includedContent = ResolveShaderIncludes(includedContent, directoryPath);


            size_t pos = processedSource.find(match[0].str());
            if (pos != std::string::npos) {
                processedSource.replace(pos, match[0].str().length(), includedContent);
                processedSource.append(opening_Comment);
            }
        }
    }

    return processedSource;
}

LP_Extern LP_API const void* CompileHLSLToSPIRV(std::string source_unprocessed, std::string includes_dir, std::string entryPoint, ShaderConductor::ShaderStage stage)
{
    std::string source_processed = ResolveShaderIncludes(source_unprocessed, includes_dir);

    ShaderConductor::Compiler::Options options;
    options.optimizationLevel = 3;

    ShaderConductor::Compiler::TargetDesc targetDesc;
    targetDesc.language = ShaderConductor::ShadingLanguage::SpirV;
    targetDesc.version = "spirv1.0";

    ShaderConductor::Compiler::SourceDesc sourceDesc;
    sourceDesc.source = source_processed.c_str();
    sourceDesc.entryPoint = entryPoint.c_str();
    sourceDesc.stage = stage;
    sourceDesc.fileName = "shader.hlsl";

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
