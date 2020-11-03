#define LUABIND_BUILDING

#include <luabind/config.hpp>
#include <luabind/memory.hpp>

namespace luabind
{
	LUABIND_API allocator_func allocator = nullptr;
	LUABIND_API void* allocator_context = nullptr;
}
