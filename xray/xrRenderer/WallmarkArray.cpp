#include "stdafx.h"
#include "WallmarkArray.h"
#include <stdexcept>

void WallmarkArray::Copy(IWallMarkArray& _in)
{
}

void WallmarkArray::AppendMark(LPCSTR s_textures)
{
	// create shader "effects''wallmark" + texture from s_textures
	// push to storage
}

void WallmarkArray::clear()
{
	// clear storage
}

bool WallmarkArray::empty()
{
	return true;
}

wm_shader WallmarkArray::GenerateWallmark()
{
	wm_shader result;
	// return random wallmark (collide mark) from storage
	
	return result;
}
