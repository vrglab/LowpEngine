#include "Includes/ShaderIncludes.hlsl"

float4 lp_main(VS_OUTPUT inputs) : SV_TARGET
{
    return inputs.Col;
}