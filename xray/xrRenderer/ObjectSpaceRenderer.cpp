#include "stdafx.h"
#include "ObjectSpaceRenderer.h"

ObjectSpaceRenderer::ObjectSpaceRenderer(IDiligentRenderingHost* dev)
{
	device = dev;
}

void ObjectSpaceRenderer::Copy(IObjectSpaceRender& _in)
{
}

void ObjectSpaceRenderer::dbgRender()
{
}

void ObjectSpaceRenderer::dbgAddSphere(const Fsphere& sphere, u32 colour)
{
}

void ObjectSpaceRenderer::SetShader()
{
}
