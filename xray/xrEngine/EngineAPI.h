// EngineAPI.h: interface for the CEngineAPI class.
//
//****************************************************************************
// Support for extension DLLs
//****************************************************************************

#pragma once

// Abstract 'Pure' class for DLL interface
class ENGINE_API DLL_Pure {
public:
	CLASS_ID				CLS_ID;

	DLL_Pure(void *params)	{CLS_ID=0; };
	DLL_Pure()				{CLS_ID=0; };
	virtual	DLL_Pure*		_construct		()	{ return this; 	}
	virtual ~DLL_Pure()		{};
};

// Class creation/destroying interface
extern "C" {
typedef DLL_API  DLL_Pure*	  __cdecl Factory_Create	(CLASS_ID	CLS_ID);
typedef DLL_API  void		  __cdecl Factory_Destroy	(DLL_Pure*	O);
};

// Tuning interface
extern "C" {
	typedef void __cdecl VTPause	(void);
	typedef void __cdecl VTResume	(void);
};

class ENGINE_API		CEngineAPI
{
private:
	class DynamicLibRef* pLibGame;
	HMODULE				hGame;

private:
	class DynamicLibRef* pLibRenderer;
	HMODULE				hRender;

private:
	HMODULE				hTuner;
public:
	Factory_Create*		pCreate;
	Factory_Destroy*	pDestroy;
	BOOL				tune_enabled;
	VTPause*			tune_pause	;
	VTResume*			tune_resume	;
	void				Initialize	();
	void				InitializeNotDedicated();
	void				Destroy		();

	void				CreateRendererList();

	CEngineAPI	();
	~CEngineAPI	();
};

#define NEW_INSTANCE(a)		Engine.External.pCreate(a)
#define DEL_INSTANCE(a)		{ Engine.External.pDestroy(a); a=NULL; }
