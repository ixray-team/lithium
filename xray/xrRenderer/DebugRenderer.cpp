#include "stdafx.h"
#include "DebugRenderer.h"
#include <stdexcept>

IDebugRender* DebugRenderer::_instance;

IDebugRender* DebugRenderer::Instance()
{
	if (_instance == nullptr)
	{
		_instance = new DebugRenderer();
	}

	return _instance;
}

void DebugRenderer::Render()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void DebugRenderer::add_lines(Fvector const* vertices, u32 const& vertex_count, u16 const* pairs, u32 const& pair_count, u32 const& color)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void DebugRenderer::NextSceneMode()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void DebugRenderer::ZEnable(bool bEnable)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void DebugRenderer::OnFrameEnd()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void DebugRenderer::SetShader(const debug_shader& shader)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void DebugRenderer::CacheSetXformWorld(const Fmatrix& M)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void DebugRenderer::CacheSetCullMode(CullMode)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void DebugRenderer::SetAmbient(u32 colour)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void DebugRenderer::SetDebugShader(dbgShaderHandle shdHandle)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void DebugRenderer::DestroyDebugShader(dbgShaderHandle shdHandle)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void DebugRenderer::dbg_DrawTRI(Fmatrix& T, Fvector& p1, Fvector& p2, Fvector& p3, u32 C)
{
	throw std::logic_error("The method or operation is not implemented.");
}
