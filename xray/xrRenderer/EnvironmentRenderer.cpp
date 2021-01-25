#include "stdafx.h"
#include "EnvironmentRenderer.h"
#include <stdexcept>

void EnvironmentRenderer::Copy(IEnvironmentRender& _in)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void EnvironmentRenderer::OnFrame(CEnvironment& env)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void EnvironmentRenderer::OnLoad()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void EnvironmentRenderer::OnUnload()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void EnvironmentRenderer::RenderSky(CEnvironment& env)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void EnvironmentRenderer::RenderClouds(CEnvironment& env)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void EnvironmentRenderer::OnDeviceCreate()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void EnvironmentRenderer::OnDeviceDestroy()
{
	throw std::logic_error("The method or operation is not implemented.");
}

particles_systems::library_interface const& EnvironmentRenderer::particles_systems_library()
{
	throw std::logic_error("The method or operation is not implemented.");
}
