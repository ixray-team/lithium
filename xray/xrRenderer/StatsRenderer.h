#pragma once

#include "Include/StatsRender.h"

class StatsRenderer : public IStatsRender
{
public:
	void Copy(IStatsRender& _in) override;

	void OutData1(CGameFont& F) override;
	void OutData2(CGameFont& F) override;
	void OutData3(CGameFont& F) override;
	void OutData4(CGameFont& F) override;

	void GuardVerts(CGameFont& F) override;
	void GuardDrawCalls(CGameFont& F) override;

	void SetDrawParams(IRenderDeviceRender* pRender) override;
};

