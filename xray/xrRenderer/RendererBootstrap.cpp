#include "stdafx.h"

#include "../Include/xrAPI/xrAPI.h"

#include "Renderer.h"
#include "RendererFactory.h"
#include "DrawUtilites.h"
#include "UiRenderer.h"
#include "DebugRenderer.h"

void RendererBootstrap()
{
	::Render = Renderer::Instance();
	::RenderFactory = RendererFactory::Instance();
	::DU = DrawUtilites::Instance();
	::UIRender = UiRenderer::Instance();
#ifdef DEBUG
	::DRender = DebugRenderer::Instance();
#endif	//	DEBUG

	//InitConsole();
}