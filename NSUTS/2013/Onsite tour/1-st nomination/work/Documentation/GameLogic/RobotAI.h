#ifndef WSO13_ROBOT_AI_109756
#define WSO13_ROBOT_AI_109756

#include <vector>

struct lua_State;
struct RobotProgram;
class ExtUnit;
class ExtRobot;
class World;
class Timing;

class RobotAI
{
    lua_State *state;
    ExtRobot *robot;
    int randSeed;
    int playerIdx;

    void Die();
    void InitAPI();


    struct FunctionContainer;

    bool LuaCheckError(int errorCode, const char *format, ...);
    void RunScript(const char *sourcePtr, int sourceSize, const char *name, Timing *timing);
public:
    RobotAI(ExtRobot *own);
    ~RobotAI();
    void Init(const RobotProgram &initProgram, const std::vector<char>& mainProgram, Timing *timing);
    void Think(Timing *timing);

    bool UpdateMemoryUsage(ptrdiff_t addMemory);

    //for visualizer debugging
    std::string RunDebugScript(const std::string &scriptString);
};

#endif
