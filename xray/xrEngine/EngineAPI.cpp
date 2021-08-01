// EngineAPI.cpp: implementation of the CEngineAPI class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "EngineAPI.h"
#include "../xrcdb/xrXRC.h"

#include "securom_api.h"
#include <onyx/dynlib/DynamicLibRef.h>
#include <functional>

extern xr_token* vid_quality_token;
extern u32 renderer_value; //con cmd

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

void __cdecl dummy		(void)	{
};
CEngineAPI::CEngineAPI	()
{
	hGame			= 0;
	hRender			= 0;
	pCreate			= 0;
	pDestroy		= 0;

	vid_quality_token = new xr_token();
	ZeroMemory(vid_quality_token, sizeof(xr_token));

	vid_quality_token->id = -1;
	vid_quality_token->name = '\0';
}

CEngineAPI::~CEngineAPI()
{
	delete vid_quality_token;
}

void CEngineAPI::InitializeNotDedicated()
{
}

void CEngineAPI::Initialize(void)
{
	InitializeNotDedicated();

	{
		pLibRenderer = new DynamicLibRef("xrRender_R2.dll",
			/* error handler */[&]() 
			{
				Log("! ERROR loading renderer library! LastError = %d", (u32) GetLastError());
			});

		hRender = pLibRenderer->GetHandle();
	}

	Device.ConnectToRender();

	// game	
	{
		pLibGame = new DynamicLibRef("xrGame.dll", 
			/* error handler */ [&]() 
			{ 
				Log("! ERROR loading game library! LastError = %d", (u32) GetLastError());
			});

		if (*pLibGame == false)
			return;

		hGame = pLibGame->GetHandle();
		pCreate = pLibGame->GetMethod("xrFactory_Create");
		pDestroy = pLibGame->GetMethod("xrFactory_Destroy");
	}
}

void CEngineAPI::Destroy	(void)
{
	hGame = 0;
	pCreate = 0;
	pDestroy = 0;
	Engine.Event._destroy();
	XRC.r_clear_compact();

	delete pLibGame;
}

void CEngineAPI::CreateRendererList()
{
}