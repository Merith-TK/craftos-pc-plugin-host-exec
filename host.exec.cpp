extern "C" {
	#include <lua.h>
	#include <lauxlib.h>
	#include <stdlib.h>
}
#include <CraftOS-PC.hpp>

int execute(lua_State *L) {
	const char * str = lua_tostring(L, 1);
	system(str);
	return(0)
}

static luaL_reg M[] = {
    {"exec", execute},
	{NULL,NULL}
};

static PluginInfo info("host");

extern "C" {
#ifdef _WIN32
_declspec(dllexport)
#endif

int luaopen_host(lua_State *L) {
    luaL_register(L, "host", M);
    return 1;
}

#ifdef _WIN32
_declspec(dllexport)
#endif
PluginInfo * plugin_init(PluginFunctions * func, const path_t& path) {
    return &info;
}
}