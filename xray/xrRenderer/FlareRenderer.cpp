#include "stdafx.h"
#include "FlareRenderer.h"

void FlareRenerer::Copy(IFlareRender& _in)
{
}

void FlareRenerer::CreateShader(LPCSTR sh_name, LPCSTR tex_name)
{
}

void FlareRenerer::DestroyShader()
{
}

FlareRenerer::FlareRenerer(IDiligentRenderingHost* dev)
{
	device = dev;
}
