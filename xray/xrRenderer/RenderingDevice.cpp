#include "stdafx.h"
#include "RenderingDevice.h"
#include <stdexcept>

void RenderingDevice::Copy(IRenderDeviceRender& _in)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void RenderingDevice::setGamma(float fGamma)
{
}

void RenderingDevice::setBrightness(float fGamma)
{
}

void RenderingDevice::setContrast(float fGamma)
{
}

void RenderingDevice::updateGamma()
{
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
}

void RenderingDevice::OnDeviceCreate(LPCSTR shName)
{
	Device.Statistic->OnDeviceCreate();
}

void RenderingDevice::Create(HWND hWnd, u32& dwWidth, u32& dwHeight, float& fWidth_2, float& fHeight_2, bool)
{
	//!
	// Declare function pointer
	Diligent::GetEngineFactoryOpenGLType GetEngineFactoryOpenGL = Diligent::LoadGraphicsEngineOpenGL();

	RECT rc;
	GetWindowRect(hWnd, &rc);
	dwWidth = rc.right - rc.left;
	dwHeight = rc.bottom - rc.top;

	Diligent::SwapChainDesc SCDesc;
	SCDesc.BufferCount = 1;
	SCDesc.Width = dwWidth;
	SCDesc.Height = dwHeight;

	fWidth_2 = dwWidth / 2;
	fHeight_2 = dwHeight / 2;

	auto* f = GetEngineFactoryOpenGL();
	
	Diligent::EngineGLCreateInfo dilEngineInfo;
	dilEngineInfo.Window.hWnd = hWnd;

	f->CreateDeviceAndSwapChainGL(dilEngineInfo, &dilDevice, &dilImmediateContext, SCDesc, &dilSwapChain);
}

void RenderingDevice::SetupGPU(BOOL bForceGPU_SW, BOOL bForceGPU_NonPure, BOOL bForceGPU_REF)
{
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
	return FALSE;
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
