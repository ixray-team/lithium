#include "stdafx.h"
#include "ApplicationRenderer.h"
#include <stdexcept>

//////////////////////////////////////////////////////////////////////////
// UTILITY
//////////////////////////////////////////////////////////////////////////
#include "../xrEngine/x_ray.h"
#include "../xrEngine/GameFont.h"

inline u32 calc_progress_color(u32 idx, u32 total, int stage, int max_stage)
{
	float kk = (float(stage + 1) / float(max_stage)) * (total);
	float f = 1 / (exp((float(idx) - kk) * 0.5f) + 1.0f);

	return color_argb_f(f, 1.0f, 1.0f, 1.0f);
}

#define IsSpace(ch)       ((ch) == ' ' || (ch) == '\t' || (ch) == '\r' || (ch) == '\n' || (ch) == ',' || (ch) == '.' || (ch) == ':' || (ch) == '!')

inline void parse_word(LPCSTR str, CGameFont* font, float& length, LPCSTR& next_word)
{
	length = 0.0f;
	while (*str && !IsSpace(*str))
	{
		//		length  += font->GetCharTC(*str).z;
		length += font->SizeOf_(*str);
		++str;
	}
	next_word = (*str) ? str + 1 : str;
}

inline void draw_multiline_text(CGameFont* F, float fTargetWidth, LPCSTR pszText)
{
	if (!pszText || xr_strlen(pszText) == 0)
		return;

	LPCSTR ch = pszText;
	float curr_word_len = 0.0f;
	LPCSTR next_word = NULL;

	float curr_len = 0.0f;
	string512				buff;
	buff[0] = 0;
	while (*ch)
	{
		parse_word(ch, F, curr_word_len, next_word);
		if (curr_len + curr_word_len > fTargetWidth)
		{
			F->OutNext(buff);
			curr_len = 0.0f;
			buff[0] = 0;
		}
		else
		{
			curr_len += curr_word_len;
			strncpy_s(buff + xr_strlen(buff), sizeof(buff) - xr_strlen(buff), ch, next_word - ch);
			ch = next_word;
		}
		if (0 == *next_word) //end of text
		{
			strncpy_s(buff + xr_strlen(buff), sizeof(buff) - xr_strlen(buff), ch, next_word - ch);
			F->OutNext(buff);
			break;
		}
	}
}

//////////////////////////////////////////////////////////////////////////
// IMPL
//////////////////////////////////////////////////////////////////////////
void ApplicationRenderer::Copy(IApplicationRender& _in)
{
}

void ApplicationRenderer::LoadBegin()
{
	/*
	ll_hGeom.create(FVF::F_TL, RCache.Vertex.Buffer(), RCache.QuadIB);
	sh_progress.create("hud\\default", "ui\\ui_actor_loadgame_screen");
	hLevelLogo_Add.create("hud\\default", "ui\\ui_actor_widescreen_sidepanels.dds");

	ll_hGeom2.create(FVF::F_TL, RCache.Vertex.Buffer(), NULL);
	*/
}

void ApplicationRenderer::destroy_loading_shaders()
{
	/*
	hLevelLogo.destroy		();
	sh_progress.destroy		();
	hLevelLogo_Add.destroy	();
	*/
}

void ApplicationRenderer::setLevelLogo(LPCSTR pszLogoName)
{
	//hLevelLogo.create("hud\\default", pszLogoName);
}

void ApplicationRenderer::load_draw_internal(CApplication& owner)
{
	// clear rt
	// draw progressbar
	// draw background
	// draw sides if needed
	// draw text (uses CFontRender in engine)
	VERIFY(owner.pFontSystem);
	owner.pFontSystem->Clear();
	owner.pFontSystem->SetColor(color_rgba(103, 103, 103, 255));
	owner.pFontSystem->SetAligment(CGameFont::alCenter);
	//back_size.set(_w / 2, 622.0f * k.y);
	//owner.pFontSystem->OutSet(back_size.x, back_size.y);
	owner.pFontSystem->OutNext(owner.ls_header);
	owner.pFontSystem->OutNext("");
	owner.pFontSystem->OutNext(owner.ls_tip_number);

	float fTargetWidth = 600.0f /** k.x * (b_ws ? 0.8f : 1.0f)*/;
	draw_multiline_text(owner.pFontSystem, fTargetWidth, owner.ls_tip);
	owner.pFontSystem->OnRender();
	
	// draw level-specific screenshot
}

void ApplicationRenderer::KillHW()
{
}

ApplicationRenderer::ApplicationRenderer(IDiligentRenderingHost* dev)
{
	device = dev;
}
