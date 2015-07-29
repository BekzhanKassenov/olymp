#ifndef WSO13_WORLD_216875
#define WSO13_WORLD_216875

#include "Common\DataTypes.h"
#include "GameLogic\ArrayAllocator.h"
#include "Common\Point.h"
#include "Common\TimeMemoryLimits.h"
#include "Common\IndexUtils.h"
#include <map>
#include <vector>

class ServerInterProcess;
struct RobotProgram;
class Grid;
class RobotAI;
class Timing;
struct FactoryCommands;

//===============================================================

class ExtUnit {
public:
    Unit *data;     //null for dead unit

    Point newPosition;
    
    virtual inline ~ExtUnit() {}
    inline Unit *GetData() { return data; }
    template<class UnitClass> inline UnitClass* Cast() {
        if (data->type == TypeOfUnitClass<UnitClass>::i)
            return (UnitClass*)this;
        return 0;
        //return dynamic_cast<UnitClass*>(this);
    }
};

class ExtFactory : public ExtUnit {
public:

    inline Factory *GetData() { return (Factory*)data; }
};

class ExtRobot : public ExtUnit {
public:
    std::vector<int> visibleSlots;

    //AI
    std::auto_ptr<RobotAI> ai;

    //move commands
    Point moveDelta;
    //shoot commands
    bool wantsToShoot;
    bool shootAtUnit;
    Point shootPosition;
    int shootUnitId;

    inline Robot *GetData() { return (Robot*)data; }
};

class ExtProjectile : public ExtUnit {
public:

    inline Projectile *GetData() { return (Projectile*)data; }
};

//===============================================================

template<class UC> struct TypeOfUnitClass { static const int i = -1; };
template<> struct TypeOfUnitClass<ExtFactory> { static const int i = 1; };
template<> struct TypeOfUnitClass<ExtRobot> { static const int i = 2; };
template<> struct TypeOfUnitClass<ExtProjectile> { static const int i = 3; };

//===============================================================

class World {
private:
    WorldData *data;

    std::auto_ptr<ExtUnit> units[MAX_UNITS_COUNT];
    ArrayAllocator<MAX_FACTORY_COUNT> factoriesAlloc;
    ArrayAllocator<MAX_ROBOT_COUNT> robotsAlloc;
    ArrayAllocator<MAX_PROJECTILE_COUNT> projectilesAlloc;
    int unitsCount[4];

    int idCount;
    std::map<int, int> idToSlot;

    std::auto_ptr<Timing> robotsThinkTiming[PLAYERS_COUNT];
    std::auto_ptr<Timing> robotsInitTiming[PLAYERS_COUNT];
    std::auto_ptr<Timing> strategyTiming[PLAYERS_COUNT];
    std::auto_ptr<Timing> programTiming[PLAYERS_COUNT];

    int playerScores[PLAYERS_COUNT];
    int playerRobotsCount[PLAYERS_COUNT];
    int playerRobotsMemoryUsage[PLAYERS_COUNT];
    //---------------------------------------------------

    inline int GetSlot(int id) const {
        std::map<int, int>::const_iterator it = idToSlot.find(id);
        if (it == idToSlot.end()) return -1;
        return it->second;
    }
    template<class UnitClass> inline UnitClass* Get(int index) {
        int slot = IndexToSlot(TypeOfUnitClass<UnitClass>::i, index);
        if (units[slot].get()) return units[slot]->Cast<UnitClass>();
        else return 0;
    }

    int AssignId(int slot);

    ExtFactory *AllocFactory();
    ExtRobot *AllocRobot();
    ExtProjectile *AllocProjectile();
    ExtFactory *CreateFactory(int owner, int classIdx, Point position);
    
    enum RobotInitResult{ riSuccess = 0, riTLE, riMLE };
    RobotInitResult RobotInit(ExtRobot *robot, const RobotProgram& prog);
    enum RobotThinkResult{ rtSuccess = 0, rtTLE, rtNoAI };
    RobotThinkResult RobotThink(ExtRobot *robot);
    
    bool RobotShoot(ExtRobot *robot);   //returns true on wrong shooting command
    void ProjectileExplode(ExtProjectile *proj, Grid &robotsGrid);
    void BuildRobot(ExtFactory *builder, const Grid &robotsGrid);
    void DestroyRobot(ExtRobot *robot);

    void ReceiveRobotProgramsAndInitRobots();
    std::vector<FactoryCommands> ReceiveFactoryCommands();
    void PopulateGridWithAllUnits(Grid &unitsGrid);
    void RunRobotsThinkAndSaveCommands(const Grid &unitsGrid);
    void HandleRobotsShooting();
    void PopulateGridWithAllRobots(Grid &robotsGrid);
    void MoveRobotsMC(Grid &robotsGrid);
    void MoveProjectilesMC(Grid &robotsGrid);
    bool HandleFactoryCapturing(ExtFactory *factory, const Grid &robotsGrid);
    void HandleFactoryBuilding(ExtFactory *factory, const Grid &robotsGrid, const FactoryCommands &commands, bool canBuild);
    bool UpdatePlayersScore();

    World();
public:
    static World &Get();

    //returns true when the game is over
    bool DoCycle();

    inline const WorldData* GetData() const { return data; }
    inline const ExtUnit* GetUnit(int slot) const { return units[slot].get(); }
    inline int GetScore(int player) const { return playerScores[player]; }
    inline int GetUnitsCount(int type) const { return unitsCount[type]; }
    inline int GetIdsCount() const { return idCount; }
    const FactoryClass &ClassOf(ExtFactory *unit);
    const RobotClass &ClassOf(ExtRobot *unit);
    const ProjectileClass &ClassOf(ExtProjectile *unit);
    inline bool UpdateMemoryUsage(int playerIdx, ptrdiff_t addMemory) {
        int &usage = playerRobotsMemoryUsage[playerIdx];
        if (addMemory > ROBOTS_MEMORY_LIMIT - usage)
            return false;
        usage += addMemory;
        return true;
    }

    //for debugging in visualizer
    std::string ExecuteLUAScript(int robotIndex, const std::string scriptString);
};


#endif
