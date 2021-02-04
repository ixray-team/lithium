#pragma once
#include "../Include/xrRender/LensFlareRender.h"

class LensFlareRenderer : public ILensFlareRender
{

public:
	void Copy(ILensFlareRender& _in) override;
	void Render(CLensFlare& owner, BOOL bSun, BOOL bFlares, BOOL bGradient) override;
	void OnDeviceCreate() override;
	void OnDeviceDestroy() override;

	LensFlareRenderer(class IDiligentRenderingHost* dev);
private:
	IDiligentRenderingHost* device;
};