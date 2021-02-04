#include "stdafx.h"
#include "StatsRenderer.h"
#include "IDiligentRenderingHost.h"

void StatsRenderer::Copy(IStatsRender& _in)
{
}

void StatsRenderer::OutData1(CGameFont& F)
{
}

void StatsRenderer::OutData2(CGameFont& F)
{
}

void StatsRenderer::OutData3(CGameFont& F)
{
}

void StatsRenderer::OutData4(CGameFont& F)
{
}

void StatsRenderer::GuardVerts(CGameFont& F)
{
}

void StatsRenderer::GuardDrawCalls(CGameFont& F)
{
}

void StatsRenderer::SetDrawParams(IRenderDeviceRender* pRender)
{
}

StatsRenderer::StatsRenderer(IDiligentRenderingHost* dev)
{
	device = dev;
}
