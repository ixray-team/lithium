#pragma once
#include "../Include/xrRender/FontRender.h"

class FontRenderer : public IFontRender
{

public:
	void Initialize(LPCSTR cShader, LPCSTR cTexture) override;
	void OnRender(CGameFont& owner) override;

	FontRenderer(class IDiligentRenderingHost* dev);
private:
	IDiligentRenderingHost* device;
};