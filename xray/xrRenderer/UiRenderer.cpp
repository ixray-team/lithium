#include "stdafx.h"
#include "UiRenderer.h"
#include <stdexcept>

void UiRenderer::CreateUIGeom()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void UiRenderer::DestroyUIGeom()
{
	throw std::logic_error("The method or operation is not implemented.");
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
	throw std::logic_error("The method or operation is not implemented.");
}

void UiRenderer::CacheSetXformWorld(const Fmatrix& M)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void UiRenderer::CacheSetCullMode(CullMode)
{
	throw std::logic_error("The method or operation is not implemented.");
}
