#include "GameLogic\World.h"
#include "Common\InterProcess.h"
#include "GameLogic\Grid.h"
#include "GameLogic\RobotAI.h"
#include "Common\Utils.h"
#include "Common\Timing.h"
#include "Common\TimeMemoryLimits.h"
#include <numeric>

static const double GRID_RESOLUTION = 100.0;
static const int MICROCYCLES_COUNT = 4;
static const int GAME_LENGTH_CYCLES = 10000;

inline const FactoryClass &World::ClassOf(ExtFactory *unit) { return data->factoryClasses[unit->data->classIdx]; }
inline const RobotClass &World::ClassOf(ExtRobot *unit) { return data->robotClasses[unit->data->classIdx]; }
inline const ProjectileClass &World::ClassOf(ExtProjectile *unit) { return data->projectileClasses[unit->data->classIdx]; }


World &World::Get() {
    static World obj;
    return obj;
}
World::World() {
    data = ServerInterProcess::Get().AllocateWorldData();
    memset(data, -1, sizeof(WorldData));
    data->currentTime = 0;
    data->maximalMatchTime = GAME_LENGTH_CYCLES;
    idCount = 0;
    memset(unitsCount, 0, sizeof(unitsCount));
    memset(playerScores, 0, sizeof(playerScores));
    memset(playerRobotsCount, 0, sizeof(playerRobotsCount));
    memset(playerRobotsMemoryUsage, 0, sizeof(playerRobotsMemoryUsage));
    for (int pl = 0; pl < PLAYERS_COUNT; pl++) {
        robotsThinkTiming[pl].reset(new Timing(ROBOT_THINK_TL_SOFT, ROBOT_THINK_TL_HARD));
        robotsInitTiming[pl].reset(new Timing(ROBOT_INIT_TL_SOFT, ROBOT_INIT_TL_HARD));
        strategyTiming[pl].reset(new Timing(STRATEGY_TL_SOFT, STRATEGY_TL_HARD, STRATEGY_START_BALANCE));
        programTiming[pl].reset(new Timing(PROGRAM_TL_SOFT, PROGRAM_TL_HARD, PROGRAM_START_BALANCE));
    }

    //TODO: initialize class information
    data->factoryClasses[0].radius = 50.0;
    data->factoryClasses[0].score = 100;
    data->factoryClasses[0].timeToCapture = 5000;
    data->factoryClasses[0].maxCapturingRobots = 10;
    data->robotClasses[0].timeToBuild = 50;
    data->robotClasses[0].maxHealth = 10;
    data->robotClasses[0].maxSpeed = 1.0;
    data->robotClasses[0].radius = 5.0;
    data->robotClasses[0].shootTimeCooldown = 5;
    data->robotClasses[0].totalAmmo = -1;
    data->robotClasses[0].visibilityRadius = 50.0;
    data->robotClasses[0].projectileClassIdx = 0;
    data->robotClasses[0].score = 1;
    data->projectileClasses[0].damage = 1;
    data->projectileClasses[0].isHoming = false;
    data->projectileClasses[0].speed = 4.0;
    data->projectileClasses[0].maxLifeTime = 15.0;

    if (PLAYERS_COUNT > 2) {
        for (int pl = 0; pl < PLAYERS_COUNT; pl++) {
            double angle = PI/4 + (2*PI/PLAYERS_COUNT) * pl;
            Point pos = (0.8 * Polar(angle) + Point(1.0, 1.0)) * (FIELD_SIZE/2);
            CreateFactory(pl, 0, pos);
        }
    }
    else {
        Point ctr = Point(0.5, 0.5) * FIELD_SIZE;
        double cell = FIELD_SIZE * 0.4;
        CreateFactory(0, 0, ctr + cell * Point(-1, -1));
        CreateFactory(1, 0, ctr + cell * Point(1, -1));
        CreateFactory(-1, 0, ctr + cell * Point(0, -1));
        CreateFactory(-1, 0, ctr + cell * Point(0, 0));
        CreateFactory(-1, 0, ctr + cell * Point(0, 1));
        CreateFactory(-1, 0, ctr + cell * Point(-1, 1));
        CreateFactory(-1, 0, ctr + cell * Point(1, 1));
    }

}

int World::AssignId(int slot) {
    idToSlot[idCount] = slot;
    int id = idCount++;
    return id;
}

ExtFactory *World::AllocFactory() {
    int index = factoriesAlloc.Allocate();
    if (index < 0) return 0;
    int type = TypeOfUnitClass<ExtFactory>::i;
    int slot = IndexToSlot(type, index);
    int id = AssignId(slot);

    Factory &objData = data->factories[index];
    units[slot].reset(new ExtFactory());
    units[slot]->data = &objData;
    units[slot]->data->id = id;
    units[slot]->data->type = type;

    unitsCount[type]++;
    return units[slot]->Cast<ExtFactory>();
}

ExtRobot *World::AllocRobot() {
    int index = robotsAlloc.Allocate();
    if (index < 0) return 0;
    int type = TypeOfUnitClass<ExtRobot>::i;
    int slot = IndexToSlot(type, index);
    int id = AssignId(slot);

    Robot &objData = data->robots[index];
    units[slot].reset(new ExtRobot());
    units[slot]->data = &objData;
    units[slot]->data->id = id;
    units[slot]->data->type = type;

    unitsCount[type]++;
    return units[slot]->Cast<ExtRobot>();
}

ExtProjectile *World::AllocProjectile() {
    int index = projectilesAlloc.Allocate();
    if (index < 0) return 0;
    int type = TypeOfUnitClass<ExtProjectile>::i;
    int slot = IndexToSlot(type, index);
    int id = AssignId(slot);

    Projectile &objData = data->projectiles[index];
    units[slot].reset(new ExtProjectile());
    units[slot]->data = &objData;
    units[slot]->data->id = id;
    units[slot]->data->type = type;

    unitsCount[type]++;
    return units[slot]->Cast<ExtProjectile>();
}

ExtFactory *World::CreateFactory(int owner, int classIdx, Point position) {
    ExtFactory *fact = AllocFactory();
    Factory *objData = fact->GetData();

    objData->owner = owner;
    objData->position = position;
    objData->classIdx = classIdx;
    objData->radius = ClassOf(fact).radius;

    objData->robotClassIdx = -1;
    objData->buildTimeRemaining = 0;
    objData->capturingPlayer = owner;
    objData->captureProgressTime = 0;

    return fact;
}


//**********************************************************************************************


bool World::DoCycle() {
    //a single grid structure for all the time
    static Grid grid(GRID_RESOLUTION);
//================================Add TL balance=================================
    for (int pl = 0; pl < PLAYERS_COUNT; pl++) {
        robotsThinkTiming[pl]->PassCycle();
        robotsInitTiming[pl]->PassCycle();
        strategyTiming[pl]->PassCycle();
        programTiming[pl]->PassCycle();
    }
//================================Update world=================================
    for (int pl = 0; pl < PLAYERS_COUNT; pl++)
        ServerInterProcess::Get().SendWorld(pl);
//=============================Check memory limits==============================
    if (!IsUnlimitedMode()) {
        for (int pl = 0; pl < PLAYERS_COUNT; pl++)
            if (!ServerInterProcess::Get().CheckMemoryLimit(pl)) {
                logprintf("Player %d: Memory limit exceeded (client)!\n", pl);
                ServerInterProcess::Get().DisconnectClient(pl);
            }
    }

//==============================Program new robots=============================
    ReceiveRobotProgramsAndInitRobots();
//==========================Ask for factory commands============================
    std::vector<FactoryCommands> factoryCommands = ReceiveFactoryCommands();
//==========================Get commands from robots============================
    PopulateGridWithAllUnits(grid);
    RunRobotsThinkAndSaveCommands(grid);

//==============================Game logic====================================
    HandleRobotsShooting();
    PopulateGridWithAllRobots(grid);
    //model microcycles
    for (int mc = 0; mc < MICROCYCLES_COUNT; mc++) {
        MoveRobotsMC(grid);
        MoveProjectilesMC(grid);
    }
    //handle factories
    for (int i = 0; i<MAX_FACTORY_COUNT; i++) {
        ExtFactory *fact = Get<ExtFactory>(i);
        if (!fact) continue;
        bool canBuild = HandleFactoryCapturing(fact, grid);
        int owner = fact->data->owner;
        if (owner < 0) continue;
        HandleFactoryBuilding(fact, grid, factoryCommands[owner], canBuild);
    }

//==============================Finish cycle====================================
    bool fullWin = UpdatePlayersScore();
    bool gameover = fullWin;
    //increment tact counter
    data->currentTime++;
    if (data->currentTime % 100 == 0) logprintf("%d cycles over\n", data->currentTime);
    //check win conditions
    if (data->currentTime >= data->maximalMatchTime)
        gameover = true;
    if (fullWin)
        logprintf("Full win after %d cycles\n", data->currentTime);

    return gameover;
}


//*******************************************************************************************


struct ProgramTaskData {
    int playerIdx;
    ProgramRobotsRequest request;
    std::vector<RobotProgram> answer;
    double workTime;
};
int ProgramTaskFunction(void *ptr) {
    ProgramTaskData *data = (ProgramTaskData*)ptr;
    data->workTime = ServerInterProcess::Get().SendProgramRequest(data->playerIdx, data->request, data->answer);
    return 0;
}
void World::ReceiveRobotProgramsAndInitRobots() {
    std::vector<int> unprogrammedRobotIndices[PLAYERS_COUNT];
    for (int i = 0; i<MAX_ROBOT_COUNT; i++) {
        ExtRobot* robot = Get<ExtRobot>(i);
        if (!robot) continue;
        if (robot->ai.get()) continue;
        unprogrammedRobotIndices[robot->data->owner].push_back(i);
    }
    for (int pl = 0; pl < PLAYERS_COUNT; pl++) {
        std::vector<int> &indices = unprogrammedRobotIndices[pl];
        std::random_shuffle(indices.begin(), indices.end());

        //we forbid programming too many robots per turn
        if (indices.size() > MAX_FACTORY_COUNT)
            indices.resize(MAX_FACTORY_COUNT);

        //set data for timed run
        ProgramTaskData taskData;
        taskData.playerIdx = pl;
        ProgramRobotsRequest &req = taskData.request;

        //check that player has time balance
        Timing *timing = programTiming[pl].get();
        if (timing->AllowedToRun()) {
            req.skipped = false;
            req.robotsCount = indices.size();
            for (int i = 0; i < indices.size(); i++) {
                taskData.request.robotIndex[i] = indices[i];
                taskData.request.robotId[i] = Get<ExtRobot>(indices[i])->data->id;
            }
        }
        else {
            req.skipped = true;
            req.robotsCount = 0;
            logprintf("Player %d TLE: Program request skipped\n", pl);
        }

        //run with hard time limit (changing balance manually)
        int tmp;
        if (!timing->Run(ProgramTaskFunction, &taskData, tmp, true)) {
            logprintf("Hard time limit exceeded on Program (player = %d)!\n", pl);
            ServerInterProcess::Get().DisconnectClient(pl);
        }
        timing->AccountTime(taskData.workTime);

        std::vector<RobotProgram>& progs = taskData.answer;
        assert(progs.size() <= indices.size());
        for (int i = 0; i < taskData.answer.size(); i++) {
            int rId = taskData.answer[i].robotId;

            //we ignore incorrect commands here
            int pos = -1;
            for (int j = 0; j < taskData.request.robotsCount; j++)
                if (rId == taskData.request.robotId[j]) {
                    pos = j;
                    taskData.request.robotId[j] = -1;
                    break;
                }
            if (pos < 0)
                continue;

            int slot = GetSlot(rId);
            RobotInitResult err = RobotInit(units[slot]->Cast<ExtRobot>(), progs[i]);
            if (err != riSuccess) {
                logprintf("Player %d %cLE: Init finished only for %d of %d robots\n", pl, (err==riTLE ? 'T' : 'M'), i, progs.size());
                break;
            }
        }
    }
}

World::RobotInitResult World::RobotInit(ExtRobot *robot, const RobotProgram &prog) {
    int pl = robot->data->owner;
    Timing *timing = robotsInitTiming[pl].get();
    if (ROBOTS_MEMORY_LIMIT - playerRobotsMemoryUsage[pl] < ROBOT_MEMORY_REQUIRED_FOR_INIT) {
        logprintf("Player %d: Memory limit exceeded (robots)!\n", pl);
        ServerInterProcess::Get().DisconnectClient(pl, true);
        ServerInterProcess::Get().Terminate();
        //return riMLE;
    }
    if (!timing->AllowedToRun())
        return riTLE;
    robot->ai.reset(new RobotAI(robot));
    robot->ai->Init(prog, ServerInterProcess::Get().GetMainRobotProgram(pl), timing);
    return riSuccess;
}

struct StrategyTaskData {
    int playerIdx;
    StrategyRequest request;
    FactoryCommands answer;
    double workTime;
};
int StrategyTaskFunction(void *ptr) {
    StrategyTaskData *data = (StrategyTaskData*)ptr;
    data->workTime = ServerInterProcess::Get().SendStrategyRequest(data->playerIdx, data->request, data->answer);
    return 0;
}
std::vector<FactoryCommands> World::ReceiveFactoryCommands() {
    std::vector<FactoryCommands> factoryCommands(PLAYERS_COUNT);
    for (int pl = 0; pl < PLAYERS_COUNT; pl++) {
        //set data for the timed run
        StrategyTaskData taskData;
        taskData.playerIdx = pl;

        Timing *timing = strategyTiming[pl].get();
        //check that player has time balance
        if (timing->AllowedToRun())
            taskData.request.skipped = false;
        else {
            logprintf("Player %d TLE: Strategy request skipped\n", pl);
            taskData.request.skipped = true;
        }

        //perform a task with hard TL
        int tmp;
        if (!timing->Run(StrategyTaskFunction, &taskData, tmp, true)) {
            logprintf("Hard time limit exceeded on Strategy (player = %d)!\n", pl);
            ServerInterProcess::Get().DisconnectClient(pl);
        }
        timing->AccountTime(taskData.workTime);

        factoryCommands[pl] = taskData.answer;
    }
    return factoryCommands;
}

void World::PopulateGridWithAllUnits(Grid &visibilityGrid) {
    visibilityGrid.Clear();
    for (int i = 0; i<MAX_UNITS_COUNT; i++) {
        ExtUnit *unit = units[i].get();
        if (!unit) continue;
        if (unit->data->id < 0) continue;
        visibilityGrid.Insert(i, unit->data->position, unit->data->radius);
    }
}

void World::RunRobotsThinkAndSaveCommands(const Grid &visibilityGrid) {
    //get lists of robots of each player (TODO: optimize this trash)
    std::vector<int> playerRobotIndices[PLAYERS_COUNT];
    for (int i = 0; i<MAX_ROBOT_COUNT; i++) {
        ExtRobot *robot = Get<ExtRobot>(i);
        if (!robot) continue;
        assert(robot->data->id >= 0 && robot->data->owner >= 0);
        playerRobotIndices[robot->data->owner].push_back(i);
    }
    //ask robots for commands
    for (int pl = 0; pl < PLAYERS_COUNT; pl++) {
        std::vector<int> &rIndices = playerRobotIndices[pl];
        std::random_shuffle(rIndices.begin(), rIndices.end());

        int i;
        for (i = 0; i < rIndices.size(); i++) {
            ExtRobot *robot = Get<ExtRobot>(rIndices[i]);

            //get the set of visible units
            robot->visibleSlots = visibilityGrid.GetCollidingTags(
                robot->data->position,
                ClassOf(robot).visibilityRadius
            );

            //ensure that the robot itself is the first one
            int mySlot = IndexToSlot(2, rIndices[i]);
            int idx = std::find(robot->visibleSlots.begin(), robot->visibleSlots.end(), mySlot) - robot->visibleSlots.begin();
            assert(idx < robot->visibleSlots.size());
            std::swap(robot->visibleSlots[0], robot->visibleSlots[idx]);

            RobotThinkResult err = RobotThink(robot);
            if (err == rtTLE) {
                logprintf("Player %d TLE: Think finished only for %d of %d robots\n", pl, i, rIndices.size());
                break;
            }
        }

        //set default behavior for all TLE robots
        for (i++; i < rIndices.size(); i++) {
            ExtRobot *robot = Get<ExtRobot>(rIndices[i]);
            robot->visibleSlots.clear();
            //robot->moveDelta = Point();
            robot->wantsToShoot = false;
        }
    }
}

World::RobotThinkResult World::RobotThink(ExtRobot *robot) {
    if (!robot->ai.get())
        return rtNoAI;
    Timing *timing = robotsThinkTiming[robot->data->owner].get();
    if (!timing->AllowedToRun())
        return rtTLE;
    robot->ai->Think(timing);
    return rtSuccess;
}

void World::HandleRobotsShooting() {
    //handle robot shooting
    for (int i = 0; i<MAX_ROBOT_COUNT; i++) {
        ExtRobot *robot = Get<ExtRobot>(i);
        if (!robot) continue;

        if (RobotShoot(robot))
            robot->wantsToShoot = false;
    }
}

bool World::RobotShoot(ExtRobot *robot) {
    Robot* rData = robot->GetData();
    //handle cooldown
    int &str = rData->shootTimeRemaining;
    str = std::max(str-1, 0);

    //check if conditions are satisfied
    if (!robot->wantsToShoot)
        return false;
    if (str > 0)
        return false;
    if (rData->ammoRemaining == 0)
        return true;

    const RobotClass &robotClass = ClassOf(robot);
    int projClassIdx = robotClass.projectileClassIdx;
    const ProjectileClass &projClass = data->projectileClasses[projClassIdx];
    //note: commands are checked in robot API

    //TODO: implement various types of shooting

    if (!projClass.isHoming) {
        ExtProjectile *proj = AllocProjectile();
        if (!proj) return true;

        Projectile *pData = proj->GetData();
        pData->owner = rData->owner;
        pData->position = rData->position;
        pData->radius = 0.0;
        pData->classIdx = projClassIdx;

        pData->velocity = projClass.speed * Normalize(robot->shootPosition - rData->position);
        pData->homingTargetId = -1;
        pData->lifeTimeRemaining = std::min(!(robot->shootPosition - rData->position) / projClass.speed, projClass.maxLifeTime);

        if (rData->ammoRemaining >= 0) rData->ammoRemaining--;
        rData->shootTimeRemaining = robotClass.shootTimeCooldown;

        robot->moveDelta = Point();

        return false;
    }

    return true;

/*    else {
        for (int i = 0; i < robot->visibleSlots.size(); i++) {
            int slot = robot->visibleSlots[i];
            if (units[slot]->data->id == robot->shootUnitId)
        if ()
        }
    }*/

/*    if (isHoming) {
        if (robot->shootType == 1) {
            //TODO: find visible unit closest to position
        }
    }
    else {
        if (robot->shootType == 2) {
            robot->shootPosition = units[]
        }
    }*/
}

void World::PopulateGridWithAllRobots(Grid &collisionGrid) {
    collisionGrid.Clear();
    for (int i = 0; i<MAX_ROBOT_COUNT; i++) {
        ExtRobot *robot = Get<ExtRobot>(i);
        if (!robot) continue;
        collisionGrid.Insert(i, robot->data->position, robot->data->radius);
    }
}

void World::MoveRobotsMC(Grid &collisionGrid) {
    for (int i = 0; i<MAX_ROBOT_COUNT; i++) {
        ExtRobot *robot = Get<ExtRobot>(i);
        if (!robot) continue;

        robot->newPosition = robot->data->position + robot->moveDelta / MICROCYCLES_COUNT;
        robot->newPosition = LimitInRect(robot->newPosition, Point(), Point(1,1)*FIELD_SIZE);

        std::vector<int> coll = collisionGrid.GetCollidingTags(robot->newPosition, robot->data->radius);
        bool collision = false;
        for (int u = 0; u<coll.size(); u++) {
            if (coll[u] == i)
                continue;
            collision = true;
        }
        if (collision) continue;

        collisionGrid.Erase(i, robot->data->position, robot->data->radius);
        robot->data->position = robot->newPosition;
        collisionGrid.Insert(i, robot->data->position, robot->data->radius);
    }
}

void World::MoveProjectilesMC(Grid &collisionGrid) {
    for (int i = 0; i<MAX_PROJECTILE_COUNT; i++) {
        ExtProjectile *proj = Get<ExtProjectile>(i);
        if (!proj) continue;
        Projectile *pData = proj->GetData();

        if (ClassOf(proj).isHoming) {
            //TODO: handle homing projectiles (including explosion moment)
        }

        double modelTime = std::min(1.0 / MICROCYCLES_COUNT, pData->lifeTimeRemaining);
        pData->lifeTimeRemaining -= modelTime;
        pData->position = pData->position + pData->velocity * modelTime;

        bool explodes = !IsInRect(pData->position, Point(), Point(1,1)*FIELD_SIZE);
        if (pData->lifeTimeRemaining < EPS) explodes = true;

        if (explodes)
            ProjectileExplode(proj, collisionGrid);
    }
}

void World::ProjectileExplode(ExtProjectile *proj, Grid &robotsGrid) {
    Projectile* pData = proj->GetData();

    std::vector<int> indices = robotsGrid.GetCollidingTags(pData->position, pData->radius);
    //damage all the robots that collide with projectile
    for (int i = 0; i < indices.size(); i++) {
        int idx = indices[i];

        ExtRobot *robot = Get<ExtRobot>(idx);
        Robot *rData = robot->GetData();

        rData->health = std::min(rData->health - ClassOf(proj).damage, ClassOf(robot).maxHealth);
        if (rData->health <= 0) {
            //don't forget to remove robot from the grid!
            robotsGrid.Erase(idx, rData->position, rData->radius);
            DestroyRobot(robot);
        }
    }

    //destroy projectile
    int slot = GetSlot(pData->id);
    idToSlot.erase(pData->id);
    projectilesAlloc.Deallocate(SlotToIndex(slot));
    unitsCount[TypeOfUnitClass<ExtProjectile>::i]--;
    memset(pData, -1, sizeof(Projectile));
    units[slot].reset();
}

void World::DestroyRobot(ExtRobot *robot) {
    Robot *rData = robot->GetData();
    //destroy robot
    int slot = GetSlot(rData->id);
    idToSlot.erase(rData->id);
    robotsAlloc.Deallocate(SlotToIndex(slot));
    unitsCount[TypeOfUnitClass<ExtRobot>::i]--;
    playerRobotsCount[rData->owner]--;
    memset(rData, -1, sizeof(Robot));
    units[slot].reset();
}

bool World::HandleFactoryCapturing(ExtFactory *fact, const Grid &collisionGrid) {
    Factory *fData = fact->GetData();

    //count how many robots everyone has here
    std::vector<int> robotIndices = collisionGrid.GetCollidingTags(fData->position, fData->radius);
    int robotsInside[PLAYERS_COUNT] = {0};
    for (int j = 0; j < robotIndices.size(); j++) {
        ExtRobot *unit = Get<ExtRobot>(robotIndices[j]);
        robotsInside[unit->data->owner]++;
    }
    int allRobotsInside = std::accumulate(robotsInside, robotsInside + PLAYERS_COUNT, 0);

    //check if the factory can build
    bool canBuild = true;
    if (fData->owner < 0 || robotsInside[fData->owner] < allRobotsInside)
        canBuild = false;

    //find a player who is the only one in the field
    int onlyPlayer = -666;
    int payload = 1;
    if (allRobotsInside > 0) {
        for (int pl = 0; pl < PLAYERS_COUNT; pl++)
            if (robotsInside[pl] == allRobotsInside)
                onlyPlayer = pl;
        payload = std::min(robotsInside[onlyPlayer], ClassOf(fact).maxCapturingRobots);
    }
    else onlyPlayer = fData->owner;

    //update capture progress
    if (onlyPlayer >= -1) {
        if (fData->capturingPlayer != fData->owner && fData->capturingPlayer != onlyPlayer) {
            int &cpt = fData->captureProgressTime;
            cpt = std::max(cpt - payload, 0);
            if (cpt == 0) fData->capturingPlayer = fData->owner;
        }
        else if (onlyPlayer != fData->owner) {
            fData->capturingPlayer = onlyPlayer;
            fData->captureProgressTime += payload;
            if (fData->captureProgressTime >= ClassOf(fact).timeToCapture) {
                //change ownership and revert any build progress
                fData->owner = onlyPlayer;
                fData->robotClassIdx = -1;
                fData->buildTimeRemaining = 0;
                fData->capturingPlayer = fData->owner;
                fData->captureProgressTime = 0;
            }
        }
    }
    assert(fData->captureProgressTime == 0 || fData->capturingPlayer != fData->owner);

    return canBuild;
}

void World::HandleFactoryBuilding(ExtFactory *fact, const Grid &collisionGrid, const FactoryCommands &comms, bool canBuild) {
    Factory *fData = fact->GetData();

    //process player commands for this factory
    for (int c = 0; c < comms.commandsCount; c++) {
        //find command for this factory and ignore incorrect ones
        if (comms.factoryId[c] != fData->id) continue;
        int newRobot = comms.factoryBuildRobot[c];
        if (newRobot == fData->robotClassIdx) continue;
        //correctness check
        if (newRobot < -1 || newRobot >= ROBOT_CLASS_COUNT) continue;

        fData->robotClassIdx = newRobot;
        fData->buildTimeRemaining = 0;
        if (newRobot < 0) continue;

        fData->buildTimeRemaining = data->robotClasses[fData->robotClassIdx].timeToBuild;
    }

    //check if it can not/should not build
    if (!canBuild)
        return;
    if (fData->robotClassIdx < 0)
        return;

    //build
    fData->buildTimeRemaining--;
    if (fData->buildTimeRemaining > 0)
        return;
    //ensure units count limit on player
    if (playerRobotsCount[fData->owner] == MAX_ROBOT_COUNT / PLAYERS_COUNT)
        return;

    //spawn robot
    fData->buildTimeRemaining = data->robotClasses[fData->robotClassIdx].timeToBuild;
    BuildRobot(fact, collisionGrid);
}

void World::BuildRobot(ExtFactory *builder, const Grid &robotsGrid) {
    const Factory* fData = builder->GetData();
    Point spawnCtr = fData->position;
    double spawnRad = fData->radius;
    const RobotClass& robotClass = data->robotClasses[fData->robotClassIdx];
    double robotRad = robotClass.radius;

    static const int SPAWN_TRIES = 100;
    bool ok = false;
    Point pos;
    srand(12345);   //note: pseudorandom number with fixed seed
    for (int t = 0; !ok && t < SPAWN_TRIES; t++) {
        pos = (t == 0 ? spawnCtr : spawnCtr + Polar(dRandom(2*PI)) * dRandom(spawnRad));
        std::vector<int> indices = robotsGrid.GetCollidingTags(pos, robotRad);
        if (indices.empty()) ok = true;
    }
    //failed to spawn...
    if (!ok)
        return;
    
    ExtRobot* robot = AllocRobot();
    Robot* rData = robot->GetData();

    rData->owner = fData->owner;
    playerRobotsCount[rData->owner]++;
    rData->classIdx = fData->robotClassIdx;
    rData->position = pos;
    rData->radius = robotRad;

    rData->health = robotClass.maxHealth;
    rData->ammoRemaining = robotClass.totalAmmo;
    rData->shootTimeRemaining = 0;

    robot->ai.reset();
    robot->moveDelta = Point();
    robot->wantsToShoot = false;
}

bool World::UpdatePlayersScore() {
    memset(playerScores, 0, sizeof(playerScores));
    for (int i = 0; i < MAX_FACTORY_COUNT; i++) {
        ExtFactory *unit = Get<ExtFactory>(i);
        if (!unit) continue;
        int owner = unit->data->owner;
        if (owner < 0) continue;
        playerScores[owner] += ClassOf(unit).score;
    }
    for (int i = 0; i < MAX_ROBOT_COUNT; i++) {
        ExtRobot *unit = Get<ExtRobot>(i);
        if (!unit) continue;
        int owner = unit->data->owner;
        if (owner < 0) continue;
        playerScores[owner] += ClassOf(unit).score;
    }
    int nonzeroScoreCount = 0;
    for (int i = 0; i<PLAYERS_COUNT; i++) {
        ServerInterProcess::Get().SetCurrentScore(i, playerScores[i]);
        nonzeroScoreCount += (playerScores[i] > 0);
    }
    return nonzeroScoreCount <= 1;
}

//===========================================================================

std::string World::ExecuteLUAScript(int robotIndex, const std::string scriptString) {
    if (!IsUnlimitedMode()) {
        logprintf("Debug script execution is enabled only in unlimited mode!\n");
        return std::string("[not in unlimited mode]");
    }
    assert(robotIndex >= 0 && robotIndex < MAX_ROBOT_COUNT);
    ExtRobot *robot = Get<ExtRobot>(robotIndex);
    if (!robot) {
        logprintf("Trying to run debug script at dead robot (index = %d)!\n", robotIndex);
        return std::string("[dead robot]");
    }
    if (!robot->ai.get())
        return std::string("[uninitialized robot]");
    return robot->ai->RunDebugScript(scriptString);
}
