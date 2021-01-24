#pragma once

#include <windows.h>

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

#define LITHIUM_EXTERNAL_RENDERER

#ifdef LITHIUM_EXTERNAL_RENDERER
#ifndef PLATFORM_WIN32
#define PLATFORM_WIN32 1
#endif
#endif