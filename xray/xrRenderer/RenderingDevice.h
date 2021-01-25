#pragma once

#include "Include/RenderDeviceRender.h"

#include "DiligentCore/Graphics/GraphicsEngineOpenGL/interface/EngineFactoryOpenGL.h"
#include "DiligentCore/Graphics/GraphicsEngineOpenGL/interface/RenderDeviceGL.h"

class RenderingDevice : public IRenderDeviceRender
{
public:
	void Copy(IRenderDeviceRender& _in) override;
	void setGamma(float fGamma) override;
	void setBrightness(float fGamma) override;
	void setContrast(float fGamma) override;
	void updateGamma() override;
	void OnDeviceDestroy(BOOL bKeepTextures) override;
	void ValidateHW() override;
	void DestroyHW() override;
	void Reset(HWND hWnd, u32& dwWidth, u32& dwHeight, float& fWidth_2, float& fHeight_2) override;
	void SetupStates() override;
	void OnDeviceCreate(LPCSTR shName) override;
	void Create(HWND hWnd, u32& dwWidth, u32& dwHeight, float& fWidth_2, float& fHeight_2, bool) override;
	void SetupGPU(BOOL bForceGPU_SW, BOOL bForceGPU_NonPure, BOOL bForceGPU_REF) override;
	void overdrawBegin() override;
	void overdrawEnd() override;
	void DeferredLoad(BOOL E) override;
	void ResourcesDeferredUpload() override;
	void ResourcesGetMemoryUsage(u32& m_base, u32& c_base, u32& m_lmaps, u32& c_lmaps) override;
	void ResourcesDestroyNecessaryTextures() override;
	void ResourcesStoreNecessaryTextures() override;
	void ResourcesDumpMemoryUsage() override;
	bool HWSupportsShaderYUV2RGB() override;
	DeviceState GetDeviceState() override;
	BOOL GetForceGPU_REF() override;
	u32 GetCacheStatPolys() override;
	void Begin() override;
	void Clear() override;
	void End() override;
	void ClearTarget() override;
	void SetCacheXform(Fmatrix& mView, Fmatrix& mProject) override;
	void OnAssetsChanged() override;

};

