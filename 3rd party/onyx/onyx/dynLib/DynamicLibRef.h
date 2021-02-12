#pragma once

#include <functional>
#include <string>
#include <windows.h>

class DynamicLibRef
{
public:
	using LoadingErrorHandler = void(*)(const char*);

	template <typename RT>
	struct callResult
	{
		bool success;
		RT* result;

		operator bool() const {	return success;	}
		operator RT() const	{ return *result; }

		callResult()
		{
			success = false;
		}

		callResult(RT* cr)
		{
			success = true;
			result = cr;
		}
	};

private:
	HMODULE moduleHandle;

public:
	DynamicLibRef(std::string libName, const std::function<void()>& err = nullptr);
	~DynamicLibRef();

	template <typename T> callResult<T> Call(std::string methodName);
	template <typename T, typename RT> callResult<T> Call(std::string methodName, RT arg1);
	template <typename T, typename RT, typename RT2> callResult<T> Call(std::string methodName, RT arg1, RT2 arg2);
	template <typename T, typename RT, typename RT2, typename RT3> callResult<T> Call(std::string methodName, RT arg1, RT2 arg2, RT3 arg3);
	
	template <typename T, typename RT, typename RT2, typename RT3, typename RT4> 
	callResult<T> Call(std::string methodName, RT arg1, RT2 arg2, RT3 arg3, RT4 arg4);

	template <typename T, typename RT, typename RT2, typename RT3, typename RT4, typename RT5>
	callResult<T> Call(std::string methodName, RT arg1, RT2 arg2, RT3 arg3, RT4 arg4, RT5 arg5);

	template <typename T, typename RT, typename RT2, typename RT3, typename RT4, typename RT5, typename RT6>
	callResult<T> Call(std::string methodName, RT arg1, RT2 arg2, RT3 arg3, RT4 arg4, RT5 arg5, RT6 arg6);

	const HMODULE GetHandle() const;
	
	class _GetMethod
	{
		friend class DynamicLibRef;

	private:
		std::string methodName;
		HMODULE moduleHandle;

		_GetMethod(HMODULE _moduleHandle, const char* _methodName) : moduleHandle(_moduleHandle), methodName(_methodName) {}

	public:
		template<typename T>
		operator T()
		{
			void* method = GetProcAddress(moduleHandle, methodName.c_str());
			if (method == nullptr)
				return nullptr;

			return (T)method;
		}
	};
	
	_GetMethod GetMethod(std::string methodName) { return _GetMethod(moduleHandle, methodName.c_str()); }

	operator bool() {
		return moduleHandle != NULL;
	}
};

template <typename T>
DynamicLibRef::callResult<T> DynamicLibRef::Call(std::string methodName)
{
	if (moduleHandle == NULL)
		return callResult<T>();

	using sig = T(*)();

	void* procAddress = GetProcAddress(moduleHandle, methodName.c_str());
	if (procAddress != nullptr)
		return callResult<T>(((sig)procAddress)());

	return callResult<T>();
}

template <typename T, typename RT>
DynamicLibRef::callResult<T> DynamicLibRef::Call(std::string methodName, RT arg1)
{
	if (moduleHandle == NULL)
		return callResult<T>();

	using sig = T(*)(RT);

	void* procAddress = GetProcAddress(moduleHandle, methodName.c_str());
	if (procAddress != nullptr)
		return callResult<T>(((sig)procAddress)(arg1));

	return callResult<T>();
}

template <typename T, typename RT, typename RT2> 
DynamicLibRef::callResult<T> DynamicLibRef::Call(std::string methodName, RT arg1, RT2 arg2)
{
	if (moduleHandle == NULL)
		return callResult<T>();

	using sig = T(*)(RT, RT2);

	void* procAddress = GetProcAddress(moduleHandle, methodName.c_str());
	if (procAddress != nullptr)
		return callResult<T>(((sig)procAddress)(arg1, arg2));

	return callResult<T>();
}

template <typename T, typename RT, typename RT2, typename RT3> 
DynamicLibRef::callResult<T> DynamicLibRef::Call(std::string methodName, RT arg1, RT2 arg2, RT3 arg3)
{
	if (moduleHandle == NULL)
		return callResult<T>();

	using sig = T(*)(RT, RT2, RT3);

	void* procAddress = GetProcAddress(moduleHandle, methodName.c_str());
	if (procAddress != nullptr)
		return callResult<T>(((sig)procAddress)(arg1, arg2, arg3));

	return callResult<T>();
}

template <typename T, typename RT, typename RT2, typename RT3, typename RT4>
DynamicLibRef::callResult<T> DynamicLibRef::Call(std::string methodName, RT arg1, RT2 arg2, RT3 arg3, RT4 arg4)
{
	if (moduleHandle == NULL)
		return callResult<T>();

	using sig = T(*)(RT, RT2, RT3, RT4);

	void* procAddress = GetProcAddress(moduleHandle, methodName.c_str());
	if (procAddress != nullptr)
		return callResult<T>(((sig)procAddress)(arg1, arg2, arg3, arg4));

	return callResult<T>();
}

template <typename T, typename RT, typename RT2, typename RT3, typename RT4, typename RT5>
DynamicLibRef::callResult<T> DynamicLibRef::Call(std::string methodName, RT arg1, RT2 arg2, RT3 arg3, RT4 arg4, RT5 arg5)
{
	if (moduleHandle == NULL)
		return callResult<T>();

	using sig = T(*)(RT, RT2, RT3, RT4, RT5);

	void* procAddress = GetProcAddress(moduleHandle, methodName.c_str());
	if (procAddress != nullptr)
		return callResult<T>(((sig)procAddress)(arg1, arg2, arg3, arg4, arg5));

	return callResult<T>();
}

template <typename T, typename RT, typename RT2, typename RT3, typename RT4, typename RT5, typename RT6>
DynamicLibRef::callResult<T> DynamicLibRef::Call(std::string methodName, RT arg1, RT2 arg2, RT3 arg3, RT4 arg4, RT5 arg5, RT6 arg6)
{
	if (moduleHandle == NULL)
		return callResult<T>();

	using sig = T(*)(RT, RT2, RT3, RT4, RT5, RT6);

	void* procAddress = GetProcAddress(moduleHandle, methodName.c_str());
	if (procAddress != nullptr)
		return callResult<T>(((sig)procAddress)(arg1, arg2, arg3, arg4, arg5, arg6));

	return callResult<T>();
}