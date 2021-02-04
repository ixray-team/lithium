#include "stdafx.h"
#include "LensFlareRenderer.h"

void LensFlareRenderer::Copy(ILensFlareRender& _in)
{
}

void LensFlareRenderer::Render(CLensFlare& owner, BOOL bSun, BOOL bFlares, BOOL bGradient)
{
}

void LensFlareRenderer::OnDeviceCreate()
{
}

void LensFlareRenderer::OnDeviceDestroy()
{
}

LensFlareRenderer::LensFlareRenderer(IDiligentRenderingHost* dev)
{
	device = dev;
}
