#pragma once
#include "Include/EnvironmentRender.h"

class EnvDescRenderer : public IEnvDescriptorRender
{

public:
	void Copy(IEnvDescriptorRender& _in) override;
	void OnDeviceCreate(CEnvDescriptor& owner) override;
	void OnDeviceDestroy() override;

	EnvDescRenderer(class IDiligentRenderingHost* dev);

private:
	IDiligentRenderingHost* device = nullptr;
	CEnvDescriptor* envDescriptor = nullptr;
};
