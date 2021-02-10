#pragma once
#include "Include/ObjectSpaceRender.h"

class ObjectSpaceRenderer : public IObjectSpaceRender
{

public:
	ObjectSpaceRenderer(class IDiligentRenderingHost* dev);

	void Copy(IObjectSpaceRender& _in) override;
	void dbgRender() override;
	void dbgAddSphere(const Fsphere& sphere, u32 colour) override;
	void SetShader() override;

private:
	IDiligentRenderingHost* device;

};
