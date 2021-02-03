#include "stdafx.h"

#include "RenderingDevice.h"

#include "DiligentCore/Graphics/GraphicsEngineOpenGL/interface/EngineFactoryOpenGL.h"
#include "DiligentCore/Graphics/GraphicsEngineOpenGL/interface/RenderDeviceGL.h"

#include "DiligentCore/Graphics/GraphicsEngineVulkan/interface/EngineFactoryVk.h"
#include "DiligentCore/Graphics/GraphicsEngineVulkan/interface/RenderDeviceVk.h"

#include "DiligentCore/Graphics/GraphicsEngineD3D12/interface/EngineFactoryD3D12.h"
#include "DiligentCore/Graphics/GraphicsEngineD3D12/interface/RenderDeviceD3D12.h"

#include "DiligentCore/Graphics/GraphicsEngineD3D11/interface/EngineFactoryD3D11.h"
#include "DiligentCore/Graphics/GraphicsEngineD3D11/interface/RenderDeviceD3D11.h"

APILayer RenderingDevice::GetPreferredApiLayer(APILayer default)
{
	APILayer api = default;

	if (!!strstr(Core.Params, "--vulkan") || !!strstr(Core.Params, "-r_vk"))
		api = APILayer::Vulkan;
	if (!!strstr(Core.Params, "--opengl") || !!strstr(Core.Params, "-r_ogl"))
		api = APILayer::OpenGL;
	if (!!strstr(Core.Params, "--directx11") || !!strstr(Core.Params, "-r_dx11"))
		api = APILayer::DX11;
	if (!!strstr(Core.Params, "--directx12") || !!strstr(Core.Params, "-r_dx12"))
		api = APILayer::DX12;

	return api;
}

void RenderingDevice::Diligent_SetupDevice(APILayer api, HWND hWnd, Diligent::SwapChainDesc scDesc)
{
	using namespace Diligent;

	switch (api)
	{
	case APILayer::DX11:
	{
		EngineD3D11CreateInfo EngineCI;
#ifdef DEBUG
		EngineCI.DebugFlags |= D3D11_DEBUG_FLAG_CREATE_DEBUG_DEVICE | D3D11_DEBUG_FLAG_VERIFY_COMMITTED_SHADER_RESOURCES;
#endif

		auto GetEngineFactoryD3D11 = LoadGraphicsEngineD3D11();
		auto* pFactoryD3D11 = GetEngineFactoryD3D11();

		pFactoryD3D11->CreateDeviceAndContextsD3D11(EngineCI, &dilDevice, &dilImmediateContext);
		
		Win32NativeWindow Window{ hWnd };
		pFactoryD3D11->CreateSwapChainD3D11(dilDevice, dilImmediateContext, scDesc, FullScreenModeDesc{}, Window, &dilSwapChain);
	}
	break;

	case APILayer::DX12:
	{
		auto GetEngineFactoryD3D12 = LoadGraphicsEngineD3D12();
		EngineD3D12CreateInfo EngineCI;
#ifdef DEBUG
		// There is a bug in D3D12 debug layer that causes memory leaks!
		//EngineCI.EnableDebugLayer = true;
#endif
		auto* pFactoryD3D12 = GetEngineFactoryD3D12();
		pFactoryD3D12->CreateDeviceAndContextsD3D12(EngineCI, &dilDevice, &dilImmediateContext);
		Win32NativeWindow Window{ hWnd };
		pFactoryD3D12->CreateSwapChainD3D12(dilDevice, dilImmediateContext, scDesc, FullScreenModeDesc{}, Window, &dilSwapChain);
	}
	break;

	case APILayer::OpenGL:
	{

		auto GetEngineFactoryOpenGL = LoadGraphicsEngineOpenGL();
		auto* pFactoryOpenGL = GetEngineFactoryOpenGL();

		EngineGLCreateInfo EngineCI;
		EngineCI.Window.hWnd = hWnd;
#ifdef DEBUG
		EngineCI.CreateDebugContext = true;
#endif
		pFactoryOpenGL->CreateDeviceAndSwapChainGL(EngineCI, &dilDevice, &dilImmediateContext, scDesc, &dilSwapChain);
	}
	break;

	case APILayer::Vulkan:
	{
		EngineVkCreateInfo EngineCI;
#ifdef DEBUG
		EngineCI.EnableValidation = true;
#endif
		auto GetEngineFactoryVk = LoadGraphicsEngineVk();
		auto* pFactoryVk = GetEngineFactoryVk();
		pFactoryVk->CreateDeviceAndContextsVk(EngineCI, &dilDevice, &dilImmediateContext);

		Win32NativeWindow Window{ hWnd };
		pFactoryVk->CreateSwapChainVk(dilDevice, dilImmediateContext, scDesc, Window, &dilSwapChain);
	}
	break;
	default:
		std::cerr << "Unknown/unsupported device type";
		return;
	}
}