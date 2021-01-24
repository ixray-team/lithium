#pragma once

#include "Include/UIRender.h"

class UiRenderer : public IUIRender
{
private:
	static IUIRender* _instance;

protected:
	UiRenderer() {};

public:
	static IUIRender* Instance() {
		if (_instance == nullptr)
		{
			_instance = new UiRenderer();
		}

		return _instance;
	}

public:
	void CreateUIGeom() override;
	void DestroyUIGeom() override;

	void SetShader(IUIShader& shader) override;
	void SetAlphaRef(int aref) override;
	void SetScissor(Irect* rect = NULL) override;

	void GetActiveTextureResolution(Fvector2& res) override;
	void PushPoint(float x, float y, float z, u32 C, float u, float v) override;

	void StartPrimitive(u32 iMaxVerts, ePrimitiveType primType, ePointType pointType) override;
	void FlushPrimitive() override;

	LPCSTR UpdateShaderName(LPCSTR tex_name, LPCSTR sh_name) override;
	void CacheSetXformWorld(const Fmatrix& M) override;
	void CacheSetCullMode(CullMode) override;

};

