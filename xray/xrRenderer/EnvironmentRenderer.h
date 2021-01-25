#pragma once

#include "Include/EnvironmentRender.h"

class EnvironmentRenderer : public IEnvironmentRender
{
public:
	void Copy(IEnvironmentRender& _in) override;

	void OnFrame(CEnvironment& env) override;

	void OnLoad() override;
	void OnUnload() override;

	void RenderSky(CEnvironment& env) override;
	void RenderClouds(CEnvironment& env) override;

	void OnDeviceCreate() override;

	void OnDeviceDestroy() override;

	particles_systems::library_interface const& particles_systems_library() override;
};

