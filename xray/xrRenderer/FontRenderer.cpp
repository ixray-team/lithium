#include "stdafx.h"
#include "FontRenderer.h"

void FontRenderer::Initialize(LPCSTR cShader, LPCSTR cTexture)
{
}

void FontRenderer::OnRender(CGameFont& owner)
{
}

FontRenderer::FontRenderer(class IDiligentRenderingHost* dev)
{
	device = dev;
}
