#include "stdafx.h"
#include "RainRenderer.h"

void RainRenderer::Copy(IRainRender& _in)
{
}

void RainRenderer::Render(CEffect_Rain& owner)
{
}

const Fsphere& RainRenderer::GetDropBounds() const
{
	Fsphere result;
	
	_vector3<float> center;
	center.set(0, 0, 0);

	result.set(center, 1.0f);

	return result;
}

RainRenderer::RainRenderer(IDiligentRenderingHost* dev)
{
	device = dev;
}
