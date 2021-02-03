#include "stdafx.h"

#include "RenderingDevice.h"

Diligent::IRenderDevice* RenderingDevice::dilGetDevice()
{
	return dilDevice;
}

Diligent::IDeviceContext* RenderingDevice::dilGetImmediateContext()
{
	return dilImmediateContext;
}

Diligent::ISwapChain* RenderingDevice::dilGetSwapChain()
{
	return dilSwapChain;
}