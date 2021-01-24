#include "stdafx.h"
#include "RenderingDevice.h"
#include <stdexcept>

void RenderingDevice::Copy(IRenderDeviceRender& _in)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void RenderingDevice::setGamma(float fGamma)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void RenderingDevice::setBrightness(float fGamma)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void RenderingDevice::setContrast(float fGamma)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void RenderingDevice::updateGamma()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void RenderingDevice::OnDeviceDestroy(BOOL bKeepTextures)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void RenderingDevice::ValidateHW()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void RenderingDevice::DestroyHW()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void RenderingDevice::Reset(HWND hWnd, u32& dwWidth, u32& dwHeight, float& fWidth_2, float& fHeight_2)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void RenderingDevice::SetupStates()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void RenderingDevice::OnDeviceCreate(LPCSTR shName)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void RenderingDevice::Create(HWND hWnd, u32& dwWidth, u32& dwHeight, float& fWidth_2, float& fHeight_2, bool)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void RenderingDevice::SetupGPU(BOOL bForceGPU_SW, BOOL bForceGPU_NonPure, BOOL bForceGPU_REF)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void RenderingDevice::overdrawBegin()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void RenderingDevice::overdrawEnd()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void RenderingDevice::DeferredLoad(BOOL E)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void RenderingDevice::ResourcesDeferredUpload()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void RenderingDevice::ResourcesGetMemoryUsage(u32& m_base, u32& c_base, u32& m_lmaps, u32& c_lmaps)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void RenderingDevice::ResourcesDestroyNecessaryTextures()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void RenderingDevice::ResourcesStoreNecessaryTextures()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void RenderingDevice::ResourcesDumpMemoryUsage()
{
	throw std::logic_error("The method or operation is not implemented.");
}

bool RenderingDevice::HWSupportsShaderYUV2RGB()
{
	throw std::logic_error("The method or operation is not implemented.");
}

IRenderDeviceRender::DeviceState RenderingDevice::GetDeviceState()
{
	throw std::logic_error("The method or operation is not implemented.");
}

BOOL RenderingDevice::GetForceGPU_REF()
{
	throw std::logic_error("The method or operation is not implemented.");
}

u32 RenderingDevice::GetCacheStatPolys()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void RenderingDevice::Begin()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void RenderingDevice::Clear()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void RenderingDevice::End()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void RenderingDevice::ClearTarget()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void RenderingDevice::SetCacheXform(Fmatrix& mView, Fmatrix& mProject)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void RenderingDevice::OnAssetsChanged()
{
	throw std::logic_error("The method or operation is not implemented.");
}
