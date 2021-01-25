#include "stdafx.h"
#include "UIShader.h"

#include <stdexcept>

void UIShader::Copy(IUIShader& _in)
{
	_in.create("");
}

void UIShader::create(LPCSTR sh, LPCSTR tex /*= 0*/)
{
}

bool UIShader::inited()
{
	return false;
}

void UIShader::destroy()
{
}
