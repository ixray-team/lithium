#include "stdafx.h"
#include "UiRenderer.h"

#include "RendererFactory.h"
#include "IDiligentRenderingHost.h"

#include <stdexcept>


IUIRender* UiRenderer::_instance;

UiRenderer::UiRenderer(class IDiligentRenderingHost* dev)
{
	device = dev;
}

IUIRender* UiRenderer::Instance()
{
	if (_instance == nullptr)
	{
		IDiligentRenderingHost* host = ((RendererFactory*)RendererFactory::Instance())->GetRendererDevice();
		_instance = new UiRenderer(host);
	}

	return _instance;
}

void UiRenderer::CreateUIGeom()
{
	// UI geometry is being drawn in UI vertex shader
}

void UiRenderer::DestroyUIGeom()
{
	// UI geometry is being drawn in UI vertex shader
}

void UiRenderer::SetShader(IUIShader& shader)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void UiRenderer::SetAlphaRef(int aref)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void UiRenderer::SetScissor(Irect* rect /*= NULL*/)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void UiRenderer::GetActiveTextureResolution(Fvector2& res)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void UiRenderer::PushPoint(float x, float y, float z, u32 C, float u, float v)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void UiRenderer::StartPrimitive(u32 iMaxVerts, ePrimitiveType primType, ePointType pointType)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void UiRenderer::FlushPrimitive()
{
	throw std::logic_error("The method or operation is not implemented.");
}

LPCSTR UiRenderer::UpdateShaderName(LPCSTR tex_name, LPCSTR sh_name)
{
	return sh_name;
}

void UiRenderer::CacheSetXformWorld(const Fmatrix& M)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void UiRenderer::CacheSetCullMode(CullMode)
{
	throw std::logic_error("The method or operation is not implemented.");
}
