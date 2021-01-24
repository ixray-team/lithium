#pragma once

#include "stdafx.h"
#include "Include/DebugRender.h"

class DebugRenderer : public IDebugRender
{
private:
	static IDebugRender* _instance;

protected:
	DebugRenderer() {};

public:
	static IDebugRender* Instance();

public:
	void Render() override;


	void add_lines(Fvector const* vertices, u32 const& vertex_count, u16 const* pairs, u32 const& pair_count, u32 const& color) override;


	void NextSceneMode() override;


	void ZEnable(bool bEnable) override;


	void OnFrameEnd() override;


	void SetShader(const debug_shader& shader) override;


	void CacheSetXformWorld(const Fmatrix& M) override;


	void CacheSetCullMode(CullMode) override;


	void SetAmbient(u32 colour) override;


	void SetDebugShader(dbgShaderHandle shdHandle) override;


	void DestroyDebugShader(dbgShaderHandle shdHandle) override;


	void dbg_DrawTRI(Fmatrix& T, Fvector& p1, Fvector& p2, Fvector& p3, u32 C) override;

};

