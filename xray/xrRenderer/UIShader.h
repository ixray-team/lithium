#pragma once

#include "Include/UIShader.h"
#include "IDiligentRenderingHost.h"

class UIShader : public IUIShader
{
public:
	void Copy(IUIShader& _in) override;

	void create(LPCSTR sh, LPCSTR tex = 0) override;
	bool inited() override;
	void destroy() override;

	IDiligentRenderingHost* owner;
public:
	UIShader(class IDiligentRenderingHost* owner);

private:
	ref_ptr<struct Diligent::IShader> ps;
	ref_ptr<struct Diligent::IShader> vs;
};

