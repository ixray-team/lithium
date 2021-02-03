#include "stdafx.h"
#include "UIShader.h"

void UIShader::Copy(IUIShader& _in)
{
	_in.create(0);
}

void UIShader::create(LPCSTR sh, LPCSTR tex /*= 0*/)
{
	//#TODO: Migrate to new FS impl

	Diligent::IRenderDevice* device = owner->dilGetDevice();

	Diligent::ShaderCreateInfo ShaderCI;
	ShaderCI.SourceLanguage = Diligent::SHADER_SOURCE_LANGUAGE_HLSL;
	ShaderCI.UseCombinedTextureSamplers = true;

	{
		static const char* VSSource = R"(
struct PSInput 
{ 
    float4 pos : SV_POSITION; 
    float2 texcoord: TexCoord;
};

void main(in uint vertId : SV_VertexID, out PSInput psIn) 
{
	psIn.texcoord = float2((vertId << 1) & 2, vertId & 2);    
	psIn.pos = float4(psIn.texcoord * float2(2.0f, -2.0f) + float2(-1.0f, 1.0f), 0.0f, 1.0f);
}
)";

		ShaderCI.Desc.ShaderType = Diligent::SHADER_TYPE_VERTEX;
		ShaderCI.EntryPoint = "main";
		ShaderCI.Desc.Name = "UI vertex shader";
		ShaderCI.Source = VSSource;
		device->CreateShader(ShaderCI, &vs);
	}

	{
		static const char* PSSource = R"(
struct PSInput 
{ 
    float4 pos : SV_POSITION; 
    float2 texcoord: TexCoord;
};

struct PSOutput
{ 
    float4 Color : SV_TARGET; 
};

void main(in PSInput psIn, out PSOutput psOut)
{
    psOut.Color = float4(psIn.texcoord.x, psIn.texcoord.y, 0.0f, 1.0f);
}
)";
		ShaderCI.Desc.ShaderType = Diligent::SHADER_TYPE_PIXEL;
		ShaderCI.EntryPoint = "main";
		ShaderCI.Desc.Name = "UI pixel shader";
		ShaderCI.Source = PSSource;
		device->CreateShader(ShaderCI, &ps);
	}
}

bool UIShader::inited()
{
	return false;
}

void UIShader::destroy()
{
}

UIShader::UIShader(IDiligentRenderingHost* owner)
{
	this->owner = owner;
}
