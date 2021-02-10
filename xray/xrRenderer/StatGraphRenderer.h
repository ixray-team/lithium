#pragma once
#include "Include/StatGraphRender.h"

class StatGraphRenderer : public IStatGraphRender
{

public:
	StatGraphRenderer(class IDiligentRenderingHost* dev);

	void Copy(IStatGraphRender& _in) override;
	void OnDeviceCreate() override;
	void OnDeviceDestroy() override;
	void OnRender(CStatGraph& owner) override;

private:
	IDiligentRenderingHost* device;

};