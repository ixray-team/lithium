#pragma once

#include "Include/UIShader.h"

class UIShader : public IUIShader
{
public:
	void Copy(IUIShader& _in) override;

	void create(LPCSTR sh, LPCSTR tex = 0) override;
	bool inited() override;
	void destroy() override;
};

