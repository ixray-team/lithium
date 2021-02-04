#include "stdafx.h"
#include "EnvDescMixerRenderer.h"
#include "IDiligentRenderingHost.h"

void EnvDescMixerRenderer::Copy(IEnvDescriptorMixerRender& _in)
{
}

void EnvDescMixerRenderer::Destroy()
{
}

void EnvDescMixerRenderer::Clear()
{
}

void EnvDescMixerRenderer::lerp(IEnvDescriptorRender* inA, IEnvDescriptorRender* inB)
{
}

EnvDescMixerRenderer::EnvDescMixerRenderer(IDiligentRenderingHost* dev)
{
	device = dev;
}
