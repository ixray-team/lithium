#pragma once
#include "../Include/xrRender/RainRender.h"

class RainRenderer : public IRainRender
{

public:
	void Copy(IRainRender& _in) override;
	void Render(CEffect_Rain& owner) override;
	const Fsphere& GetDropBounds() const override;

	RainRenderer(class IDiligentRenderingHost* dev);
private:
	IDiligentRenderingHost* device;
};