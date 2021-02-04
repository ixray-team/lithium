#include "stdafx.h"
#include "RendererFactory.h"

#include <stdexcept>

#include "RenderingDevice.h"
#include "UIShader.h"
#include "StatsRenderer.h"
#include "ApplicationRenderer.h"
#include "EnvironmentRenderer.h"
#include "WallmarkArray.h"
#include "../Include/xrRender/LensFlareRender.h"
#include "../Include/xrRender/ThunderboltDescRender.h"
#include "../Include/xrRender/UISequenceVideoItem.h"
#include "EnvDescRenderer.h"
#include "EnvDescMixerRenderer.h"
#include "UISeqVideoItem.h"
#include "RainRenderer.h"
#include "LensFlareRenderer.h"
#include "FontRenderer.h"
#include "FlareRenderer.h"

IRenderFactory* RendererFactory::_instance;

IRenderFactory* RendererFactory::Instance()
{
	if (_instance == nullptr)
	{
		_instance = new RendererFactory();
	}

	return _instance;
}

IUISequenceVideoItem* RendererFactory::CreateUISequenceVideoItem()
{
	return new UISeqVideoItem(rendererDevice);
}

void RendererFactory::DestroyUISequenceVideoItem(IUISequenceVideoItem* pObject)
{
	pObject->ResetTexture();
	delete pObject;
}

IUIShader* RendererFactory::CreateUIShader()
{
	return new UIShader(rendererDevice);
}

void RendererFactory::DestroyUIShader(IUIShader* pObject)
{
	pObject->destroy();
	delete pObject;
}

void RendererFactory::DestroyStatGraphRender(IStatGraphRender* pObject)
{
	delete pObject;
}

IStatGraphRender* RendererFactory::CreateStatGraphRender()
{
	throw std::logic_error("The method or operation is not implemented.");
}

IConsoleRender* RendererFactory::CreateConsoleRender()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void RendererFactory::DestroyConsoleRender(IConsoleRender* pObject)
{
	delete pObject;
}

void RendererFactory::DestroyRenderDeviceRender(IRenderDeviceRender* pObject)
{
	pObject->Clear();
	pObject->DestroyHW();
	delete pObject;
}

IRenderDeviceRender* RendererFactory::CreateRenderDeviceRender()
{
	rendererDevice = new RenderingDevice();
	return (RenderingDevice*)rendererDevice;
}

void RendererFactory::DestroyObjectSpaceRender(IObjectSpaceRender* pObject)
{
	throw std::logic_error("The method or operation is not implemented.");
}

IObjectSpaceRender* RendererFactory::CreateObjectSpaceRender()
{
	throw std::logic_error("The method or operation is not implemented.");
}

IApplicationRender* RendererFactory::CreateApplicationRender()
{
	return new ApplicationRenderer(rendererDevice);
}

void RendererFactory::DestroyApplicationRender(IApplicationRender* pObject)
{
	pObject->destroy_loading_shaders();
	pObject->KillHW();
	delete pObject;
}

IWallMarkArray* RendererFactory::CreateWallMarkArray()
{
	return new WallmarkArray();
}

void RendererFactory::DestroyWallMarkArray(IWallMarkArray* pObject)
{
	pObject->clear();
	delete pObject;
}

void RendererFactory::DestroyStatsRender(IStatsRender* pObject)
{
	delete pObject;
}

IStatsRender* RendererFactory::CreateStatsRender()
{
	return new StatsRenderer(rendererDevice);
}

void RendererFactory::DestroyEnvironmentRender(IEnvironmentRender* pObject)
{
	delete pObject;
}

IEnvironmentRender* RendererFactory::CreateEnvironmentRender()
{
	return new EnvironmentRenderer(rendererDevice);
}

IEnvDescriptorMixerRender* RendererFactory::CreateEnvDescriptorMixerRender()
{
	return new EnvDescMixerRenderer(rendererDevice);
}

void RendererFactory::DestroyEnvDescriptorMixerRender(IEnvDescriptorMixerRender* pObject)
{
	pObject->Destroy();
	delete pObject;
}

void RendererFactory::DestroyEnvDescriptorRender(IEnvDescriptorRender* pObject)
{
	delete pObject;
}

IEnvDescriptorRender* RendererFactory::CreateEnvDescriptorRender()
{
	return new EnvDescRenderer(rendererDevice);
}

IRainRender* RendererFactory::CreateRainRender()
{
	return new RainRenderer(rendererDevice);
}

void RendererFactory::DestroyRainRender(IRainRender* pObject)
{
	delete pObject;
}

ILensFlareRender* RendererFactory::CreateLensFlareRender()
{
	return new LensFlareRenderer(rendererDevice);
}

void RendererFactory::DestroyLensFlareRender(ILensFlareRender* pObject)
{
	delete pObject;
}

void RendererFactory::DestroyThunderboltRender(IThunderboltRender* pObject)
{
	delete pObject;
}

IThunderboltRender* RendererFactory::CreateThunderboltRender()
{
	throw std::logic_error("The method or operation is not implemented.");
}

IThunderboltDescRender* RendererFactory::CreateThunderboltDescRender()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void RendererFactory::DestroyThunderboltDescRender(IThunderboltDescRender* pObject)
{
	pObject->DestroyModel();
	delete pObject;
}

void RendererFactory::DestroyFlareRender(IFlareRender* pObject)
{
	pObject->DestroyShader();
	delete pObject;
}

IFlareRender* RendererFactory::CreateFlareRender()
{
	return new FlareRenerer(rendererDevice);
}

IFontRender* RendererFactory::CreateFontRender()
{
	return new FontRenderer(rendererDevice);
}

void RendererFactory::DestroyFontRender(IFontRender* pObject)
{
	delete pObject;
}
