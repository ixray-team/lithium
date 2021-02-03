#pragma once

#include <windows.h>

#include <d3d11.h>
#include <d3d12.h>

#define VK_USE_PLATFORM_WIN32_KHR
#include <vulkan/vulkan.h>

#define ENGINE_API __declspec(dllimport)
#define XRCORE_API __declspec(dllimport)
#define ECORE_API __declspec(dllimport)

#include "../xrCore/xrCore.h"

#include "../xrCore/_types.h"
#include "../xrCore/_vector3d.h"
#include "../xrCore/_matrix.h"
#include "../xrCore/_fbox.h"
#include "../xrCore/_fbox2.h"
#include "../xrCore/_obb.h"
#include "../xrCore/_sphere.h"
#include "../xrCore/_vector2.h"
#include "../xrCore/_rect.h"

#include "../xrCDB/xrCDB.h"

#include "../xrSound/Sound.h"

#include "../xrEngine/EventAPI.h"
#include "../xrEngine/pure.h"
#include "../xrEngine/device.h"

#define LITHIUM_EXTERNAL_RENDERER

#ifdef LITHIUM_EXTERNAL_RENDERER
#ifndef PLATFORM_WIN32
#define PLATFORM_WIN32 1
#endif
#endif

#include <DiligentCore/Common/interface/BasicMath.hpp>
#include <DiligentCore/Common/interface/RefCntAutoPtr.hpp>

#include <DiligentCore/Graphics/GraphicsEngine/interface/GraphicsTypes.h>

#include <DiligentCore/Graphics/GraphicsEngine/interface/RenderDevice.h>
#include <DiligentCore/Graphics/GraphicsEngine/interface/DeviceContext.h>
#include <DiligentCore/Graphics/GraphicsEngine/interface/SwapChain.h>

template<typename T> using ref_ptr = typename Diligent::template RefCntAutoPtr<T>;