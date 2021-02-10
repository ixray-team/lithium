#pragma once
#include "Include/ThunderboltRender.h"

class ThunderboltRenderer : public IThunderboltRender
{

public:
	ThunderboltRenderer(class IDiligentRenderingHost* dev);

	void Copy(IThunderboltRender& _in) override;
	void Render(CEffect_Thunderbolt& owner) override;

private:
	IDiligentRenderingHost* device;

};