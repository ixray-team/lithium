#pragma once
#include "Include/ThunderboltDescRender.h"

class ThunderboltDescRenderer : public IThunderboltDescRender
{

public:
	ThunderboltDescRenderer(class IDiligentRenderingHost* dev);

	void Copy(IThunderboltDescRender& _in) override;
	void CreateModel(LPCSTR m_name) override;
	void DestroyModel() override;

private:
	IDiligentRenderingHost* device;

};