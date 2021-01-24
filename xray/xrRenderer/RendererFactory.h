#pragma once

#include "stdafx.h"

#include "Include/RenderFactory.h"

class RendererFactory : public IRenderFactory
{
private:
	static IRenderFactory* _instance;

protected:
	RendererFactory() {};

public:
	static IRenderFactory* Instance() {
		if (_instance == nullptr)
		{
			_instance = new RendererFactory();
		}

		return _instance;
	}

public:
	IUISequenceVideoItem* CreateUISequenceVideoItem() override;
	void DestroyUISequenceVideoItem(IUISequenceVideoItem* pObject) override;

	IUIShader* CreateUIShader() override;
	void DestroyUIShader(IUIShader* pObject) override;

	IStatGraphRender* CreateStatGraphRender() override;
	void DestroyStatGraphRender(IStatGraphRender* pObject) override;


	IConsoleRender* CreateConsoleRender() override;
	void DestroyConsoleRender(IConsoleRender* pObject) override;

	IRenderDeviceRender* CreateRenderDeviceRender() override;
	void DestroyRenderDeviceRender(IRenderDeviceRender* pObject) override;

	IObjectSpaceRender* CreateObjectSpaceRender() override;
	void DestroyObjectSpaceRender(IObjectSpaceRender* pObject) override;

	IApplicationRender* CreateApplicationRender() override;
	void DestroyApplicationRender(IApplicationRender* pObject) override;

	IWallMarkArray* CreateWallMarkArray() override;
	void DestroyWallMarkArray(IWallMarkArray* pObject) override;

	IStatsRender* CreateStatsRender() override;
	void DestroyStatsRender(IStatsRender* pObject) override;

	IEnvironmentRender* CreateEnvironmentRender() override;
	void DestroyEnvironmentRender(IEnvironmentRender* pObject) override;

	IEnvDescriptorMixerRender* CreateEnvDescriptorMixerRender() override;
	void DestroyEnvDescriptorMixerRender(IEnvDescriptorMixerRender* pObject) override;

	IEnvDescriptorRender* CreateEnvDescriptorRender() override;
	void DestroyEnvDescriptorRender(IEnvDescriptorRender* pObject) override;

	IRainRender* CreateRainRender() override;
	void DestroyRainRender(IRainRender* pObject) override;

	ILensFlareRender* CreateLensFlareRender() override;
	void DestroyLensFlareRender(ILensFlareRender* pObject) override;

	IThunderboltRender* CreateThunderboltRender() override;
	void DestroyThunderboltRender(IThunderboltRender* pObject) override;

	IThunderboltDescRender* CreateThunderboltDescRender() override;
	void DestroyThunderboltDescRender(IThunderboltDescRender* pObject) override;

	IFlareRender* CreateFlareRender() override;
	void DestroyFlareRender(IFlareRender* pObject) override;

	IFontRender* CreateFontRender() override;
	void DestroyFontRender(IFontRender* pObject) override;
};

