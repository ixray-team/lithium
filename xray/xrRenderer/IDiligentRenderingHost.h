#pragma once

#include "stdafx.h"

class IDiligentRenderingHost
{
public:
	virtual Diligent::IRenderDevice* dilGetDevice() = 0;
	virtual Diligent::IDeviceContext* dilGetImmediateContext() = 0;
	virtual Diligent::ISwapChain* dilGetSwapChain() = 0;
};