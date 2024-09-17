// ==============================================//
//                                               //
//     code developed by bobbobson21/kyle        //
//                                               //
// ==============================================//

#define lmathlib_normalizeextention
#define LUA_LIB

#include "lprefix.h"

#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"


static int math_NormaliseWithExponent(lua_State* L) {
    int ArgCount = lua_gettop(L);  /* number of arguments */
    lua_Number Length = 0;
    lua_Number Exponent = l_mathop(fabs)(luaL_checknumber(L, 2));


    for (int i = 3; i <= ArgCount; i++)
    {
        lua_Number ValToNum = l_mathop(fabs)(luaL_checknumber(L, i)); //gets the valuse in dimantion I
        Length += (ValToNum * ValToNum);
    }
    Length = l_mathop(sqrt)Length; //gets the square root of the total resulting in us having the length of the vector

    for (int i = 3; i <= ArgCount; i++)
    {
        lua_Number ValToNum = (luaL_checknumber(L, i));
        lua_pushnumber((ValToNum / Length) * Exponent); //end result
    }

    return 1;
}

static int math_Normalise(lua_State* L) {
    int ArgCount = lua_gettop(L);  /* number of arguments */
    lua_Number Length = 0;

    for (int i = 2; i <= ArgCount; i++)
    {
        lua_Number ValToNum = l_mathop(fabs)(luaL_checknumber(L, i)); //gets the valuse in dimantion I
        Length += (ValToNum * ValToNum); //squares it
    }
    Length = l_mathop(sqrt)Length; //gets the square root of the total resulting in us having the length of the vector

    for (int i = 2; i <= ArgCount; i++)
    {
        lua_Number ValToNum = (luaL_checknumber(L, i));
        lua_pushnumber(ValToNum / Length); //end result
    }

    return 1;
}
