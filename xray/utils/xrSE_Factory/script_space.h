////////////////////////////////////////////////////////////////////////////
//	Module 		: script_space.h
//	Created 	: 22.09.2003
//  Modified 	: 01.04.2004
//	Author		: Dmitriy Iassenev
//	Description : XRay Script space
////////////////////////////////////////////////////////////////////////////

#pragma once

#include "script_space_forward.h"

#pragma warning(push)

#pragma warning(disable:4244)
#pragma warning(disable:4995)
#pragma warning(disable:4530)
#pragma warning(disable:4267)

extern "C" {
	#include <lua.h>
	#include <lualib.h>
	#include <lauxlib.h>
};

#pragma warning(push)
#pragma warning(disable:4995 4297 4913)
#include <luabind/luabind.hpp>
#pragma warning(pop)

#include <luabind/object.hpp>
#include <luabindex/functor.hpp>
#include <luabind/operator.hpp>
#include <luabind/adopt_policy.hpp>
#include <luabind/return_reference_to_policy.hpp>
#include <luabind/out_value_policy.hpp>
#include <luabind/iterator_policy.hpp>

template <typename T1, typename T2>
IC	T1 *_dynamic_cast(T2 *p2)
{
	return			(smart_cast<T1*>(p2));
}

extern	string4096	g_ca_stdout;

#pragma warning(pop)

typedef lua_State CLuaVirtualMachine;