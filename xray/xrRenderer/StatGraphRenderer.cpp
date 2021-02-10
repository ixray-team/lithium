#include "stdafx.h"
#include "StatGraphRenderer.h"

StatGraphRenderer::StatGraphRenderer(IDiligentRenderingHost* dev)
{
	device = dev;
}

void StatGraphRenderer::Copy(IStatGraphRender& _in)
{
}

void StatGraphRenderer::OnDeviceCreate()
{
}

void StatGraphRenderer::OnDeviceDestroy()
{
}

void StatGraphRenderer::OnRender(CStatGraph& owner)
{
}
