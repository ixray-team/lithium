#include "stdafx.h"
#include "UIShader.h"

#include <onyx/fs/FileSystem.h>

void UIShader::Copy(IUIShader& _in)
{
	_in.create(0);
}

void UIShader::create(LPCSTR sh, LPCSTR tex)
{
	Diligent::IRenderDevice* device = owner->dilGetDevice();

	Diligent::ShaderCreateInfo ShaderCI;
	ShaderCI.SourceLanguage = Diligent::SHADER_SOURCE_LANGUAGE_HLSL;
	ShaderCI.UseCombinedTextureSamplers = true;

	// --- VERTEX SHADER CREATION
	do
	{
		if (vs)
			break;

		std::string shaderFileName = std::string("/shaders/") + sh + "_vs.hlsl";
		std::replaceAll(shaderFileName, "\\", "/");
		if (!onyx::fs().exists(shaderFileName))
		{
			create_default_vs(tex);
			break;
		}

		onyx::File file = onyx::fs().file(shaderFileName);

		file->Open(onyx::IFile::FileMode::In);

		onyx::fsize_t fileLength = file->Size();
		u8* buffer = new u8[fileLength];
		ZeroMemory(buffer, fileLength);
		file->Read(buffer, fileLength);
		file->Close();
		file = nullptr;

		ShaderCI.Desc.ShaderType = Diligent::SHADER_TYPE_VERTEX;
		ShaderCI.EntryPoint = "main";
		ShaderCI.Desc.Name = "UI vertex shader";
		ShaderCI.Source = (char*)buffer;
		device->CreateShader(ShaderCI, &vs);

		delete[] buffer;

		if (!vs)
		{
			create_default_vs(tex);
			break;
		}

	} while (false);

	// --- PIXEL SHADER CREATION
	do
	{
		if (vs)
			break;

		std::string shaderFileName = std::string("/shaders/") + sh + "_ps.hlsl";
		if (!onyx::fs().exists(shaderFileName))
		{
			create_default_ps(tex);
			break;
		}

		onyx::File file = onyx::fs().file(shaderFileName);

		file->Open(onyx::IFile::FileMode::In);

		onyx::fsize_t fileLength = file->Size();
		u8* buffer = new u8[fileLength];
		ZeroMemory(buffer, fileLength);
		file->Read(buffer, fileLength);
		file->Close();
		file = nullptr;

		ShaderCI.Desc.ShaderType = Diligent::SHADER_TYPE_PIXEL;
		ShaderCI.EntryPoint = "main";
		ShaderCI.Desc.Name = "UI pixel shader";
		ShaderCI.Source = (char*)buffer;
		device->CreateShader(ShaderCI, &ps);

		delete[] buffer;

		if (!vs)
		{
			create_default_vs(tex);
			break;
		}

	} while (false);
}

bool UIShader::inited()
{
	return ps && vs;
}

void UIShader::destroy()
{
	if (ps) ps.Release();
	if (vs) vs.Release();
}

UIShader::UIShader(IDiligentRenderingHost* owner)
{
	this->owner = owner;
}

void UIShader::create_default_vs(LPCSTR tex /*= 0*/)
{

}

void UIShader::create_default_ps(LPCSTR tex /*= 0*/)
{

}
