struct VS_INPUT
{
    float4 Pos : POSITION;
    float4 Col : COLOR;
};

struct VS_OUTPUT
{
    float4 Pos : SV_POSITION;
    float4 Col : COLOR;
};

struct LP_Matricies
{
    float4x4 worldMatrix;
    float4x4 viewMatrix;
    float4x4 projectionMatrix;
};

struct LP_Material
{
    float4 diffuseColor;
    float4 specularColor;
    float specularPower;
    float3 padding; // Padding for alignment
};