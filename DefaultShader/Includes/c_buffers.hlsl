#include "Commons.hlsl"

cbuffer TransformBuffer : register(b0)
{
    LP_Matricies matrricies;
};

cbuffer CameraBuffer : register(b1)
{
    float3 cameraPosition;
    float padding;
};

cbuffer MaterialBuffer : register(b3)
{
    LP_Material material;
};