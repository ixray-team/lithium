#pragma once

#include "Include/ApplicationRender.h"

class ApplicationRenderer : public IApplicationRender
{
public:
	void Copy(IApplicationRender& _in) override;

	void LoadBegin() override;
	void destroy_loading_shaders() override;
	void setLevelLogo(LPCSTR pszLogoName) override;
	void load_draw_internal(CApplication& owner) override;
	void KillHW() override;
};

