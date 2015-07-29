#ifndef WSO13_DATA_TYPES_981684
#define WSO13_DATA_TYPES_981684

#pragma pack(push, 1)   //less data = faster IPC

//==============================Geometry===========================

struct CoordsXY {
    double x;
    double y;
};

//========================Unit object (base)=======================

struct Unit {
    //unique identifier of the unit (they are assigned sequentally)
    //if it is negative(-1), then this unit is dead.
    int id;

    //0 - first player, 1 - second player, -1 - neutral
    short owner;
    //1 - factory, 2 - robot, 3 - projectile
    short type;

    //current location of the unit
    CoordsXY position;
    //collision radius (immutable)
    double radius;

    //index in the array of classes for the corresponding unit type
    //e.g. index of RobotClass
    int classIdx;
};

//==========================Unit instances=========================

struct Factory : public Unit {
    //what it builds now (negative(-1) means nothing)
    int robotClassIdx;

    //after this time is over, the new robot appears
    int buildTimeRemaining;

    //if no capture is in progress, the owner index is set
    int capturingPlayer;
    //how much time of capturing is already done
    int captureProgressTime;
};

struct Robot : public Unit {
    int health;
    
    //robot can shoot only when this timer is over
    int shootTimeRemaining;

    //how many shots it can do (negative(-1) means infinity)
    int ammoRemaining;
};

struct Projectile : public Unit {
    //current velocity vector
    CoordsXY velocity;

    int homingTargetId;

    //after this time is over, the projectile falls on the ground
    double lifeTimeRemaining;
};

//======================Common properties of units=================

struct FactoryClass {
    //territory of the factory: robots spawn in it, used as capture area
    double radius;

    //how many robot-cycles is necessary to capture factory
    int timeToCapture;

    //maximum number of robots that are counted when calculating capture speed
    int maxCapturingRobots;

    //adds to player score after the game time expires
    int score;
};

struct RobotClass {
    double radius;

    double visibilityRadius;

    int maxHealth;

    //maximal movement per cycle
    double maxSpeed;

    //what sort of stuff it shoots
    int projectileClassIdx;
    //minimal time between shots
    int shootTimeCooldown;
    //maximal number of shots that can be done (negative(-1) means infinity)
    int totalAmmo;

    //how long it takes to build it at the factory
    int timeToBuild;

    //adds to player score after the game time expires
    int score;
};

struct ProjectileClass {
    //amount of damage on hit (may be negative)
    int damage;
    //0 - "drop on that point", 1 - homing missile
    int isHoming;
    //normal flying speed
    double speed;
    //for how long it can fly
    double maxLifeTime;
};

//=========================World information=========================

//number of players playing the game (always two)
const int PLAYERS_COUNT = 2;
//the field territory is [0;F]x[0;F]. where F = :
const double FIELD_SIZE = 1000.0;

const int FACTORY_CLASS_COUNT = 1;
const int ROBOT_CLASS_COUNT = 1;
const int PROJECTILE_CLASS_COUNT = 1;

const int MAX_FACTORY_COUNT = 10;
const int MAX_ROBOT_COUNT = 1024;
const int MAX_PROJECTILE_COUNT = 5120;

//Note: this data is regularly sent to clients
struct WorldData {
    //actually, number of cycles passed since the game started
    int currentTime;
    //the limit on the game length
    int maximalMatchTime;

    //unit classes data
    FactoryClass factoryClasses[FACTORY_CLASS_COUNT];
    RobotClass robotClasses[ROBOT_CLASS_COUNT];
    ProjectileClass projectileClasses[PROJECTILE_CLASS_COUNT];
    // unit instances data
    Factory factories[MAX_FACTORY_COUNT];
    Robot robots[MAX_ROBOT_COUNT];
    Projectile projectiles[MAX_PROJECTILE_COUNT];
};

const int MAX_UNITS_COUNT = MAX_FACTORY_COUNT + MAX_ROBOT_COUNT + MAX_PROJECTILE_COUNT;
const int WORLD_DATA_SIZE = sizeof(WorldData);

#pragma pack(pop)

#endif
