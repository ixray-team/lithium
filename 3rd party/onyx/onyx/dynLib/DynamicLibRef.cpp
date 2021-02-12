#include "DynamicLibRef.h"

#include <windows.h>

DynamicLibRef::DynamicLibRef(std::string libName, const std::function<void()>& err)
{
	moduleHandle = LoadLibraryA(libName.c_str());
	if (moduleHandle == NULL)
	{
		err();
	}
}

DynamicLibRef::~DynamicLibRef()
{
	if (moduleHandle)
		FreeLibrary(moduleHandle);
}

const HMODULE DynamicLibRef::GetHandle() const
{
	return moduleHandle;
}
