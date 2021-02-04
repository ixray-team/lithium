#pragma once
#include "Include/EnvironmentRender.h"

class EnvDescMixerRenderer : public IEnvDescriptorMixerRender
{

public:
	void Copy(IEnvDescriptorMixerRender& _in) override;
	void Destroy() override;
	void Clear() override;
	void lerp(IEnvDescriptorRender* inA, IEnvDescriptorRender* inB) override;

	EnvDescMixerRenderer(class IDiligentRenderingHost* dev);

private:
	IDiligentRenderingHost* device;

};