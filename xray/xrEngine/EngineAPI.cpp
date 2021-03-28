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
	hTuner			= 0;
	pCreate			= 0;
	pDestroy		= 0;
	tune_pause		= dummy	;
	tune_resume		= dummy	;

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

	//////////////////////////////////////////////////////////////////////////
	// vTune
	tune_enabled		= FALSE;
	if (strstr(Core.Params,"-tune"))	{
		LPCSTR			g_name	= "vTuneAPI.dll";
		Log				("Loading DLL:",g_name);
		hTuner			= LoadLibrary	(g_name);
		if (0==hTuner)	R_CHK			(GetLastError());
		R_ASSERT2		(hTuner,"Intel vTune is not installed");
		tune_enabled	= TRUE;
		tune_pause		= (VTPause*)	GetProcAddress(hTuner,"VTPause"		);	R_ASSERT(tune_pause);
		tune_resume		= (VTResume*)	GetProcAddress(hTuner,"VTResume"	);	R_ASSERT(tune_resume);
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