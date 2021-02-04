#include "stdafx.h"

#include "EnvDescRenderer.h"
#include "IDiligentRenderingHost.h"

void EnvDescRenderer::Copy(IEnvDescriptorRender& _in)
{
}

void EnvDescRenderer::OnDeviceCreate(CEnvDescriptor& owner)
{
	envDescriptor = &owner;
}

void EnvDescRenderer::OnDeviceDestroy()
{
}

EnvDescRenderer::EnvDescRenderer(IDiligentRenderingHost* dev)
{
	device = dev;
}
