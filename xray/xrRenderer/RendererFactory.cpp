#include "stdafx.h"
#include "RendererFactory.h"

#include <stdexcept>
#include "RenderingDevice.h"

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
	throw std::logic_error("The method or operation is not implemented.");
}

void RendererFactory::DestroyUISequenceVideoItem(IUISequenceVideoItem* pObject)
{
	throw std::logic_error("The method or operation is not implemented.");
}

IUIShader* RendererFactory::CreateUIShader()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void RendererFactory::DestroyUIShader(IUIShader* pObject)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void RendererFactory::DestroyStatGraphRender(IStatGraphRender* pObject)
{
	throw std::logic_error("The method or operation is not implemented.");
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
	throw std::logic_error("The method or operation is not implemented.");
}

void RendererFactory::DestroyRenderDeviceRender(IRenderDeviceRender* pObject)
{
	throw std::logic_error("The method or operation is not implemented.");
}

IRenderDeviceRender* RendererFactory::CreateRenderDeviceRender()
{
	return new RenderingDevice();
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
	throw std::logic_error("The method or operation is not implemented.");
}

void RendererFactory::DestroyApplicationRender(IApplicationRender* pObject)
{
	throw std::logic_error("The method or operation is not implemented.");
}

IWallMarkArray* RendererFactory::CreateWallMarkArray()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void RendererFactory::DestroyWallMarkArray(IWallMarkArray* pObject)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void RendererFactory::DestroyStatsRender(IStatsRender* pObject)
{
	throw std::logic_error("The method or operation is not implemented.");
}

IStatsRender* RendererFactory::CreateStatsRender()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void RendererFactory::DestroyEnvironmentRender(IEnvironmentRender* pObject)
{
	throw std::logic_error("The method or operation is not implemented.");
}

IEnvironmentRender* RendererFactory::CreateEnvironmentRender()
{
	throw std::logic_error("The method or operation is not implemented.");
}

IEnvDescriptorMixerRender* RendererFactory::CreateEnvDescriptorMixerRender()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void RendererFactory::DestroyEnvDescriptorMixerRender(IEnvDescriptorMixerRender* pObject)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void RendererFactory::DestroyEnvDescriptorRender(IEnvDescriptorRender* pObject)
{
	throw std::logic_error("The method or operation is not implemented.");
}

IEnvDescriptorRender* RendererFactory::CreateEnvDescriptorRender()
{
	throw std::logic_error("The method or operation is not implemented.");
}

IRainRender* RendererFactory::CreateRainRender()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void RendererFactory::DestroyRainRender(IRainRender* pObject)
{
	throw std::logic_error("The method or operation is not implemented.");
}

ILensFlareRender* RendererFactory::CreateLensFlareRender()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void RendererFactory::DestroyLensFlareRender(ILensFlareRender* pObject)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void RendererFactory::DestroyThunderboltRender(IThunderboltRender* pObject)
{
	throw std::logic_error("The method or operation is not implemented.");
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
	throw std::logic_error("The method or operation is not implemented.");
}

void RendererFactory::DestroyFlareRender(IFlareRender* pObject)
{
	throw std::logic_error("The method or operation is not implemented.");
}

IFlareRender* RendererFactory::CreateFlareRender()
{
	throw std::logic_error("The method or operation is not implemented.");
}

IFontRender* RendererFactory::CreateFontRender()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void RendererFactory::DestroyFontRender(IFontRender* pObject)
{
	throw std::logic_error("The method or operation is not implemented.");
}
