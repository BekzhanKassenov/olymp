#include "GameLogic\RobotAI.h"
#include "Common\TransferredData.h"
#include "Common\Utils.h"
#include "Common\TimeMemoryLimits.h"
#include "Common\Timing.h"
#include "GameLogic\World.h"
#include "Common\InterProcess.h"
#include <malloc.h>
#include <cstdlib>

#ifdef USE_LUA_JIT
#include "LUAJit\lua.hpp"
#else
#include "LUA\lua.hpp"
#endif

//copy-pasted from lauxlib.c
static void *l_alloc (void *ud, void *ptr, size_t osize, size_t nsize) {
  if (!IsUnlimitedMode()) {
    //updating memory usage and checking for MLE
    RobotAI *ai = (RobotAI*)ud;
    bool ok = (nsize <= ROBOTS_MEMORY_LIMIT && ai->UpdateMemoryUsage(nsize - osize));
    if (!ok)
        return NULL;
  }
  //standard code for allocator
  if (nsize == 0) {
    free(ptr);
    return NULL;
  }
  else
    return realloc(ptr, nsize);
}
inline bool RobotAI::UpdateMemoryUsage(ptrdiff_t addMemory) {
    return World::Get().UpdateMemoryUsage(robot->data->owner, addMemory);
}

#define LUA_OPEN(state, type) \
	lua_pushcfunction(state, luaopen_##type); \
	lua_call(state, 0, 0);
#define LUA_REMOVE_GLOBAL(state, name) \
    lua_pushnil(state); \
    lua_setglobal(state, #name);

RobotAI::RobotAI(ExtRobot *own) {
    robot = own;
    randSeed = own->data->id;
    playerIdx = robot->data->owner;

    state = lua_newstate(l_alloc, this);
    if (!state) {
        logprintf("Cannot create LUA state (owner = %d, id = %d)!\n", playerIdx, robot->GetData()->id);
        //it happens in case of MLE: simply disqualify the player and terminate game
        ServerInterProcess::Get().DisconnectClient(playerIdx, true);
        ServerInterProcess::Get().Terminate();
    }
//    luaJIT_setmode(state, 0, LUAJIT_MODE_ENGINE|LUAJIT_MODE_OFF );

    if (IsUnlimitedMode())
        luaL_openlibs(state);
    else {
        //include necessary libraries
    	LUA_OPEN(state, base);
        LUA_OPEN(state, string);
        LUA_OPEN(state, table);
        LUA_OPEN(state, math);
    
        //remove forbidden functions
        LUA_REMOVE_GLOBAL(state, dofile)
        LUA_REMOVE_GLOBAL(state, load)
        LUA_REMOVE_GLOBAL(state, loadfile)
        LUA_REMOVE_GLOBAL(state, loadstring)

        //redefine print
        luaL_loadstring(state, "");
        lua_setglobal(state, "print");
    }

    InitAPI();
}

void RobotAI::Die() {
    if (state) {
        lua_close(state);
        state = 0;
    }
}

RobotAI::~RobotAI() {
    Die();
}


static RobotAI *check_api (lua_State *L) {
    void *ud = lua_touserdata(L, 1);
    luaL_argcheck(L, ud != NULL, 1, "'api userdata' expected");
    return *((RobotAI**)ud);
}
#define check_commands check_api
#define check_info check_api

struct RobotAI::FunctionContainer {
    static int commands_move_by_delta (lua_State *L) {
        RobotAI *ai = check_commands(L);
    
        Point pnt(luaL_checknumber(L, 2), luaL_checknumber(L, 3));
        luaL_argcheck(L, IsFinite(pnt.x), 2, "bad number");
        luaL_argcheck(L, IsFinite(pnt.y), 3, "bad number");
    
        double maxSpeed = World::Get().ClassOf(ai->robot).maxSpeed;
        pnt = LimitNorm(pnt, maxSpeed);
    
        ai->robot->moveDelta = pnt;
    
        lua_pushnumber(L, pnt.x);
        lua_pushnumber(L, pnt.y);
        return 2;
    }
    
    static int commands_shoot_stop (lua_State *L) {
        RobotAI *ai = check_commands(L);
        ai->robot->wantsToShoot = false;
        return 0;
    }
    
    static int commands_shoot_at_pos (lua_State *L) {
        RobotAI *ai = check_commands(L);
    
        Point pnt(luaL_checknumber(L, 2), luaL_checknumber(L, 3));
        luaL_argcheck(L, IsFinite(pnt.x), 2, "bad number");
        luaL_argcheck(L, IsFinite(pnt.y), 3, "bad number");
    
        ai->robot->wantsToShoot = true;
        ai->robot->shootAtUnit = false;
        ai->robot->shootPosition = pnt;
    
        return 0;
    }
    
    static int commands_shoot_at_unit (lua_State *L) {
        RobotAI *ai = check_commands(L);
    
        int id = luaL_checkint(L, 2);
        luaL_argcheck(L, id >= 0 && id < World::Get().GetIdsCount(), 2, "unit ID out of range");
    
        ai->robot->wantsToShoot = true;
        ai->robot->shootAtUnit = true;
        ai->robot->shootUnitId = id;
    
        return 0;
    }
    
    static int info_count (lua_State *L) {
        RobotAI *ai = check_info(L);
        lua_pushinteger(L, ai->robot->visibleSlots.size() - 1);
        return 1;
    }

    static int info_time (lua_State *L) {
        RobotAI *ai = check_info(L);
        lua_pushinteger(L, World::Get().GetData()->currentTime);
        return 1;
    }
    
    static inline ExtUnit *unit_by_visible_index(lua_State *L, RobotAI *ai) {
        int idx = lua_tointeger(L, 2);
        luaL_argcheck(L, idx >= 0 && idx < ai->robot->visibleSlots.size(), 2, "visible unit index out of range");
        int slot = ai->robot->visibleSlots[idx];
        return const_cast<ExtUnit*>(World::Get().GetUnit(slot));
    }
    
    #define IMPLEMENT_INFO_FIELD(name, cond, type, value)\
        static int info_##name (lua_State *L) {\
            RobotAI *ai = check_info(L);\
            ExtUnit *unit = unit_by_visible_index(L, ai);\
            if (cond) lua_push##type(L, value);\
            else lua_pushnil(L);\
            return 1;\
        }
    //unit fields
    IMPLEMENT_INFO_FIELD(id, true, integer, unit->data->id)
    IMPLEMENT_INFO_FIELD(owner, true, integer, unit->data->owner)
    IMPLEMENT_INFO_FIELD(type, true, integer, unit->data->type)
    IMPLEMENT_INFO_FIELD(classIdx, true, integer, unit->data->classIdx)
    IMPLEMENT_INFO_FIELD(radius, true, number, unit->data->radius)
    static int info_position (lua_State *L) {
        RobotAI *ai = check_info(L);
        ExtUnit *unit = unit_by_visible_index(L, ai);
        lua_pushnumber(L, unit->data->position.x);
        lua_pushnumber(L, unit->data->position.y);
        return 2;
    }
    //robot fields
    IMPLEMENT_INFO_FIELD(health, unit->data->type == TypeOfUnitClass<ExtRobot>::i, integer, unit->Cast<ExtRobot>()->GetData()->health)
    IMPLEMENT_INFO_FIELD(shootTimeRemaining, unit->data->id == ai->robot->data->id, integer, unit->Cast<ExtRobot>()->GetData()->shootTimeRemaining)
    IMPLEMENT_INFO_FIELD(ammoRemaining, unit->data->id == ai->robot->data->id, integer, unit->Cast<ExtRobot>()->GetData()->ammoRemaining)
    //robot class fields
    IMPLEMENT_INFO_FIELD(maxHealth, unit->data->type == TypeOfUnitClass<ExtRobot>::i, integer, World::Get().ClassOf(unit->Cast<ExtRobot>()).maxHealth)
    IMPLEMENT_INFO_FIELD(visibilityRadius, unit->data->type == TypeOfUnitClass<ExtRobot>::i, number, World::Get().ClassOf(unit->Cast<ExtRobot>()).visibilityRadius)
    IMPLEMENT_INFO_FIELD(shootTimeCooldown, unit->data->type == TypeOfUnitClass<ExtRobot>::i, integer, World::Get().ClassOf(unit->Cast<ExtRobot>()).shootTimeCooldown)
    //robot: class fields of projectiles
    IMPLEMENT_INFO_FIELD(projSpeed, unit->data->type == TypeOfUnitClass<ExtRobot>::i, number, World::Get().GetData()->projectileClasses[World::Get().ClassOf(unit->Cast<ExtRobot>()).projectileClassIdx].speed)
    IMPLEMENT_INFO_FIELD(projDamage, unit->data->type == TypeOfUnitClass<ExtRobot>::i, integer, World::Get().GetData()->projectileClasses[World::Get().ClassOf(unit->Cast<ExtRobot>()).projectileClassIdx].damage)
    IMPLEMENT_INFO_FIELD(projIsHoming, unit->data->type == TypeOfUnitClass<ExtRobot>::i, integer, World::Get().GetData()->projectileClasses[World::Get().ClassOf(unit->Cast<ExtRobot>()).projectileClassIdx].isHoming)
    //projectile fields
    static int info_velocity (lua_State *L) {
        RobotAI *ai = check_info(L);
        ExtUnit *unit = unit_by_visible_index(L, ai);
        ExtProjectile *proj = unit->Cast<ExtProjectile>();
        if (proj) {
            const CoordsXY &velXY = proj->GetData()->velocity;
            lua_pushnumber(L, velXY.x);
            lua_pushnumber(L, velXY.y);
        }
        else {
            lua_pushnil(L);
            lua_pushnil(L);
        }
        return 2;
    }
    //projectile class fields
    IMPLEMENT_INFO_FIELD(damage, unit->data->type == TypeOfUnitClass<ExtProjectile>::i, integer, World::Get().ClassOf(unit->Cast<ExtProjectile>()).damage)
    IMPLEMENT_INFO_FIELD(isHoming, unit->data->type == TypeOfUnitClass<ExtProjectile>::i, integer, World::Get().ClassOf(unit->Cast<ExtProjectile>()).isHoming)
    IMPLEMENT_INFO_FIELD(maxLifeTime, unit->data->type == TypeOfUnitClass<ExtProjectile>::i, number, World::Get().ClassOf(unit->Cast<ExtProjectile>()).maxLifeTime)
    //mixed
    static int info_speed (lua_State *L) {
        RobotAI *ai = check_info(L);
        ExtUnit *unit = unit_by_visible_index(L, ai);
        switch (unit->data->type) {
            case TypeOfUnitClass<ExtRobot>::i:
                lua_pushnumber(L, World::Get().ClassOf(unit->Cast<ExtRobot>()).maxSpeed);
                break;
            case TypeOfUnitClass<ExtProjectile>::i:
                lua_pushnumber(L, World::Get().ClassOf(unit->Cast<ExtProjectile>()).speed);
                break;
            default:
                lua_pushnil(L);
        }
        return 1;
    }
};

void RobotAI::InitAPI() {
    //initialize commands API
    RobotAI **apiData = (RobotAI**)lua_newuserdata(state, sizeof(this));
    *apiData = this;

    //set api_meta.__index = api_meta
    luaL_newmetatable(state, "api_meta");
    lua_pushstring(state, "__index");
    lua_pushvalue(state, -2);
    lua_settable(state, -3);

    //add constants
    lua_pushstring(state, "field_size");
    lua_pushnumber(state, FIELD_SIZE);
    lua_settable(state, -3);

    //add C functions to api_meta
    static const struct luaL_reg api_lib [] = {
      //commands
      {"move_by_delta", FunctionContainer::commands_move_by_delta},
      {"shoot_stop", FunctionContainer::commands_shoot_stop},
      {"shoot_at_pos", FunctionContainer::commands_shoot_at_pos},
//      {"shoot_at_unit", FunctionContainer::commands_shoot_at_unit},
      //info
        {"count", FunctionContainer::info_count},
        {"time", FunctionContainer::info_time},
        //unit
        {"id", FunctionContainer::info_id},
        {"owner", FunctionContainer::info_owner},
        {"type", FunctionContainer::info_type},
        {"class_idx", FunctionContainer::info_classIdx},
        {"position", FunctionContainer::info_position},
        {"radius", FunctionContainer::info_radius},
        //robot
        {"health", FunctionContainer::info_health},
        {"shoot_time_remaining", FunctionContainer::info_shootTimeRemaining},
        {"ammo_remaining", FunctionContainer::info_ammoRemaining},
        //robot class
        {"max_health", FunctionContainer::info_maxHealth},
        {"visibility_radius", FunctionContainer::info_visibilityRadius},
        {"shoot_time_cooldown", FunctionContainer::info_shootTimeCooldown},
        {"max_speed", FunctionContainer::info_speed},
        //robot projectile class
        {"projectile_speed", FunctionContainer::info_projSpeed},
        {"projectile_damage", FunctionContainer::info_projDamage},
//        {"projectile_is_homing", FunctionContainer::info_projIsHoming},
        //projectile
        {"velocity", FunctionContainer::info_velocity},
        //projectile class
        {"damage", FunctionContainer::info_damage},
//        {"is_homing", FunctionContainer::info_isHoming},
        {"max_life_time", FunctionContainer::info_maxLifeTime},
        {"speed", FunctionContainer::info_speed},
      {NULL, NULL}
    };
    luaL_openlib(state, NULL, api_lib, 0);
    lua_setmetatable(state, -2);

    lua_setglobal(state, "api");
}


bool RobotAI::LuaCheckError(int errorCode, const char *format, ...) {
    if (errorCode) {
        //get error message
        const char *errMessage = lua_tostring(state, -1);
        //write user-specified message to log
        va_list args;
        va_start(args, format);
        logvprintf(format, args);
        va_end(args);
        //write LUA error message to log
        logprintf("%s\n", errMessage);
        //remove error message from stack
        lua_pop(state, -1);

        return true;
    }
    return false;
}

int timed_lua_pcall(void *ptr) {
    return lua_pcall((lua_State*)ptr, 0, 0, 0);
}

void RobotAI::RunScript(const char *sourcePtr, int sourceSize, const char *name, Timing *timing) {
    int err = luaL_loadbuffer(state, sourcePtr, sourceSize, name);
    if (LuaCheckError(err, "Error loading script \"%s\" (owner = %d, id = %d):\n", name, playerIdx, robot->data->id))
        return;

    bool ok_htl = timing->Run(timed_lua_pcall, state, err);
    if (!ok_htl) {
        logprintf("Hard time limit exceeded on Init:%s (owner = %d, id = %d)!\n", name, playerIdx, robot->data->id);
        //zero player's score and terminate game
        ServerInterProcess::Get().DisconnectClient(playerIdx, true);
        ServerInterProcess::Get().Terminate();
    }
    LuaCheckError(err, "Error running script \"%s\" (owner = %d, id = %d):\n", name, playerIdx, robot->GetData()->id);
}

void RobotAI::Init(const RobotProgram &initProg, const std::vector<char>& mainProgram, Timing *timing) {
    //set data string
    lua_pushlstring(state, initProg.rawData + initProg.stringStart, initProg.stringEnd - initProg.stringStart);
    lua_setglobal(state, "data");

    //run init script
    RunScript(
        initProg.rawData + initProg.scriptStart,
        initProg.scriptEnd - initProg.scriptStart,
        "InitScript",
        timing
    );

    //run main program script
    RunScript(
        &mainProgram[0],
        mainProgram.size() - 1,
        "MainProgram",
        timing
    );

    //check that Think function is set
    lua_getglobal(state, "Think");
    if (!lua_isfunction(state, -1)) {
        logprintf("Function Think is not set (owner = %d, id = %d)\n", playerIdx, robot->GetData()->id);
        Die();
    }
}

void RobotAI::Think(Timing *timing) {
    if (state == 0) return;

    lua_getglobal(state, "Think");
    srand(randSeed);

    int err;
    bool ok_htl = timing->Run(timed_lua_pcall, state, err);
    if (!ok_htl) {
        logprintf("Hard time limit exceeded on Think (owner = %d, id = %d)!\n", playerIdx, robot->data->id);
        //zero player's score and terminate game
        ServerInterProcess::Get().DisconnectClient(playerIdx, true);
        ServerInterProcess::Get().Terminate();
    }
    LuaCheckError(err, "Error on Think (owner = %d, id = %d):\n", playerIdx, robot->data->id);

    randSeed = (rand() << 15) ^ rand();
}

std::string RobotAI::RunDebugScript(const std::string &scriptString) {
    if (state == 0)
        return std::string("[badly initializated]");

    int topIndex = lua_gettop(state);
    int err = luaL_dostring(state, scriptString.c_str());
    if (err) {
        const char *errMessage = lua_tostring(state, -1);
        std::string ret(errMessage);
        lua_pop(state, -1);
        return ret;
    }
    int nresults = lua_gettop(state) - topIndex;

    if (nresults == 0)
        return std::string("[no return values]");

    const char PrintFunctionCode[] = 
"function pretty_print(value)\n"
    "local done = {}\n"
    "local indent = 0\n"
    "local function pretty_print_rec(obj)\n"
        "local sb = {}\n"
        "if (type(obj) == \"table\") and (not done[obj]) then\n"
            "done[obj] = true\n"
            "table.insert(sb, \"{\\n\")\n"
            "for key, value in pairs (obj) do\n"
                "indent = indent+1\n"
                "table.insert(sb, string.rep (\" \", indent))\n"
                "table.insert(sb, string.format(\"%s = \", tostring(key)))\n"
                "table.insert(sb, pretty_print_rec(value))\n"
                "table.insert(sb, \"\\n\")\n"
                "indent = indent-1\n"
            "end\n"
            "table.insert(sb, string.rep (\" \", indent))\n"
            "table.insert(sb, \"}\")\n"
            "return table.concat(sb)\n"
        "else\n"
            "return string.format(\"\\\"%s\\\"\", tostring(obj))\n"
        "end\n"
    "end\n"
    "return pretty_print_rec(value, done, indent)\n"
"end\n";
    err = luaL_dostring(state, PrintFunctionCode);
    if (LuaCheckError(err, "Failed to load pretty printer function\n"))
        return std::string("[pretty printer corrupt]");

    std::vector<std::string> results;
    for (int i = 0; i < nresults; i++) {
        lua_getglobal(state, "pretty_print");
        lua_pushvalue(state, -2);
        err = lua_pcall(state, 1, 1, 0);
        if (LuaCheckError(err, "Pretty printer function failed\n"))
            return std::string("[pretty printer failed]");
        results.push_back(lua_tostring(state, -1));
        lua_pop(state, 2);
    }

    std::reverse(results.begin(), results.end());
    std::string retStr;
    for (int i = 0; i < results.size(); i++) {
        retStr += results[i];
        retStr += "\n";
    }

    return retStr;
}
