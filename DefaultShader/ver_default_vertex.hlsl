#include "Includes/ShaderIncludes.hlsl"

VS_OUTPUT lp_main(VS_INPUT input )
{
    VS_OUTPUT output;
    output.Pos = input.Pos;
    output.Col = input.Col;
    return output;
}