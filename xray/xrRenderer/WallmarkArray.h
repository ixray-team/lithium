#pragma once

#include "Include/WallMarkArray.h"

class WallmarkArray : public IWallMarkArray
{
public:
	void Copy(IWallMarkArray& _in) override;

	void AppendMark(LPCSTR s_textures) override;
	void clear() override;
	bool empty() override;
	wm_shader GenerateWallmark() override;
};

