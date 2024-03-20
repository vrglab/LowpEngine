#include "pch.h"
#include "ShaderEngine.h"
#include <ShaderConductor/ShaderConductor.hpp>

void ShaderEngine::Dummy()
{
}

void ShaderEngine::CompileShadersForReleaseCompilation(std::string shaders_dir, std::string includes_dir)
{
    AssetsDatabase shaders_data_base = { {}, {} };

    for (const auto& entry : fs::directory_iterator(shaders_dir)) {
        if (entry.is_regular_file() && entry.path().extension() == ".hlsl") {
            std::filesystem::path filename = entry.path().filename();

            std::string shader = read_bytes(entry.path().string());

            const void* spirv = ShaderEngineUtils::CompileHLSLToSPIRV(shader, includes_dir, "lp_main", GetShaderStage(filename.string()), filename.string());

            std::string compiled_shader = reinterpret_cast<const char*>(spirv);

            shaders_data_base.ImportBufferedFileAsAsset(compiled_shader, entry.path().filename().string());
        }
    }
    AssetsDatabase::GenerateDatabaseFiles(shaders_data_base.hrid_table, shaders_data_base.assets_batch, "");
}

ShaderConductor::ShaderStage ShaderEngine::GetShaderStage(std::string filename)
{
    ShaderConductor::ShaderStage stage = ShaderConductor::ShaderStage::ComputeShader;

    if (std::memcmp(filename.c_str(), vertex_filename, 3) == 0) {
        stage = ShaderConductor::ShaderStage::VertexShader;
    }

    if (std::memcmp(filename.c_str(), fragment_filename, 3) == 0) {
        stage = ShaderConductor::ShaderStage::PixelShader;
    }

    if (std::memcmp(filename.c_str(), geometry_filename, 3) == 0) {
        stage = ShaderConductor::ShaderStage::GeometryShader;
    }

    if (std::memcmp(filename.c_str(), hull_filename, 3) == 0) {
        stage = ShaderConductor::ShaderStage::HullShader;
    }

    if (std::memcmp(filename.c_str(), domain_filename, 3) == 0) {
        stage = ShaderConductor::ShaderStage::DomainShader;
    }

    if (std::memcmp(filename.c_str(), compute_filename, 3) == 0) {
        stage = ShaderConductor::ShaderStage::ComputeShader;
    }

    if (std::memcmp(filename.c_str(), num_filename, 3) == 0) {
        stage = ShaderConductor::ShaderStage::NumShaderStages;
    }

    return stage;
}
