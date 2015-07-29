#ifndef WSO13_TRANSFERRED_DATA_068409
#define WSO13_TRANSFERRED_DATA_068409

#include "Common\DataTypes.h"

#pragma pack(push, 1)

struct StrategyRequest {
    bool skipped;   //if true, then client must not run player's code
};


//clients send this data as an answer to a Strategy request
struct FactoryCommands {
    int commandsCount;
    int factoryId[MAX_FACTORY_COUNT];
    int factoryBuildRobot[MAX_FACTORY_COUNT];

    //a set of pairs (id; class) means:
    //  "Switch the class of robot we build at factory (id) to (class)!"
    //   class = -1 means "Stop building anything."
};

//the server sends this request to a client when one or several new robots of the player has been spawned
struct ProgramRobotsRequest {
    int robotsCount;
    int robotIndex[MAX_FACTORY_COUNT];
    int robotId[MAX_FACTORY_COUNT];

    //a set of id-s of the new robots to be programmed
    //Note: player can learn about their positions by using API to access WorldData.

    bool skipped;   //if true, then client must not run player's code
};

//maximal total amount of bytes that can be sent to one new robot
const int MAX_PROGRAM_SIZE = 1024;

//a client sends a set of these structs as an answer to a Program request
struct RobotProgram {
    int robotId;
    char rawData[MAX_PROGRAM_SIZE];
    int stringStart, stringEnd;
    int scriptStart, scriptEnd;

    //both string and script are byte arrays
    //string(Start/End) defines the segment of rawData, where the string is located.
    //script(Start/End) defines the segment of rawData, where the script is located.
    //obviously, these segments must not overlap =)
};

#pragma pack(pop)

#endif
