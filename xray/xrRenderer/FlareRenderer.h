#pragma once
#include "../Include/xrRender/LensFlareRender.h"

class FlareRenerer : public IFlareRender
{

public:
	void Copy(IFlareRender& _in) override;
	void CreateShader(LPCSTR sh_name, LPCSTR tex_name) override;
	void DestroyShader() override;

	FlareRenerer(class IDiligentRenderingHost* dev);
private:
	IDiligentRenderingHost* device;
};