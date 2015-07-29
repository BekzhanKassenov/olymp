#include "Common\InterProcess.h"
#include "Common\Point.h"
#include "Common\Utils.h"
#include "Client\SolutionAdapter.h"
#include <cassert>

const int MAX_MAIN_ROBOT_PROGRAM_SIZE = 100<<10;

int playerIndex;
const WorldData *pWorld;

std::vector<RobotProgram> HandleProgramRequest(const ProgramRobotsRequest &req, double &workTime) {
    workTime = 0.0;
    std::vector<RobotProgram> answer;

    if (req.skipped)
        return answer;

    for (int i = 0; i < req.robotsCount; i++) {
        int index = req.robotIndex[i];
        const Robot &robot = pWorld->robots[index];
        assert(robot.id == req.robotId[i]);

        double beginTime = GetTime();
        std::pair<std::string, std::string> res = Program(index);
        workTime += GetTime() - beginTime;

        //check program size limit
        int szStr = res.first.size();
        int szSc = res.second.size();
        if (szStr + szSc > MAX_PROGRAM_SIZE) {
            logprintf("Program for robot (id = %d) is too large: %d + %d = %d !\n", robot.id, szStr, szSc, szStr + szSc);
            res.first.clear();
            res.second.clear();
        }

        RobotProgram prog;
        prog.robotId = req.robotId[i];
        prog.stringStart = 0;
        prog.stringEnd = res.first.size();
        prog.scriptStart = MAX_PROGRAM_SIZE - res.second.size();
        prog.scriptEnd = MAX_PROGRAM_SIZE;
        memcpy(prog.rawData + prog.stringStart, res.first.c_str(), res.first.size());
        memcpy(prog.rawData + prog.scriptStart, res.second.c_str(), res.second.size());

        answer.push_back(prog);
    }

    return answer;
}

FactoryCommands HandleStrategyRequest(const StrategyRequest &req, double &workTime) {
    workTime = 0.0;
    FactoryCommands answer;
    answer.commandsCount = 0;

    if (req.skipped)
        return answer;

    double beginTime = GetTime();
    std::map<int, int> res = Strategy();
    workTime = GetTime() - beginTime;

    int k = 0;
    for (std::map<int, int>::iterator it = res.begin(); it != res.end(); it++) {
        //check that the player owns a factory with this ID
        bool ok = false;
        for (int i = 0; i < MAX_FACTORY_COUNT; i++) {
            const Factory& fact = pWorld->factories[i];
            if (fact.id == it->first && fact.owner == playerIndex)
                ok = true;
        }
        if (!ok) {
            logprintf("Player tries to set command for a wrong unit (id = %d)!\n", it->first);
            continue;
        }
        //check that there is such robot class (-1 = build nothing)
        if (it->second < -1 || it->second >= ROBOT_CLASS_COUNT) {
            logprintf("Player tries to build an unknown robot (class = %d)!\n", it->second);
            continue;
        }
        //check for duplicate factories
        for (int i = 0; i < k; i++)
            if (answer.factoryId[i] == it->first)
                ok = false;
        if (!ok) {
            logprintf("Duplicate factory command ignored (id = %d)\n", it->first);
            continue;
        }

        answer.factoryId[k] = it->first;
        answer.factoryBuildRobot[k] = it->second;
        k++;
    }
    answer.commandsCount = k;

    return answer;
}

std::vector<char> LoadMainRobotProgram(const char *filename) {
    if (!filename) {
        logprintf("No main robot program specified (default = empty).\n");
        return std::vector<char>(1, 0);
    }
    FILE *f = fopen(filename, "rb");
    if (!f) {
        logprintf("Cannot read main robot program from file \"%s\"!\n", filename);
        return std::vector<char>(1, 0);
    }

    fseek(f, 0, SEEK_END);
    int fsize = ftell(f);
    fseek(f, 0, SEEK_SET);
    fsize = std::min(fsize, MAX_MAIN_ROBOT_PROGRAM_SIZE);
    std::vector<char> res(fsize + 1);
    fread(&res[0], fsize, 1, f);
    res.back() = 0;

    fclose(f);
    logprintf("Read main robot program (%d bytes)\n", fsize);
    return res;
}

int main(int argc, char **argv) {
    //establish connection to server (receive player index)
    ClientInterProcess::Get().Init();
    playerIndex = ClientInterProcess::Get().GetPlayerIndex();
    //set log file
    char logfilename[256];
    sprintf(logfilename, "ClientLog_%d.txt", playerIndex);
    SetLogFileName(logfilename);
    //read main robot program and send it to server
    std::vector<char> mainRobotProgram = LoadMainRobotProgram(argc >= 2 ? argv[1] : 0);
    ClientInterProcess::Get().SendMainRobotProgram(mainRobotProgram);
    //get pointer to world data
    pWorld = ClientInterProcess::Get().GetWorldData();

    //greetings to log file
    logprintf("My player index = %d\n", playerIndex);
    //logprintf("MaxHealth = %d\n", pWorld->robotClasses[0].maxHealth);

    while (1) {
        ClientInterProcess::Get().ReceiveWorld();

        {
            double worktime;
            ProgramRobotsRequest req;
            ClientInterProcess::Get().ReceiveProgramRequest(req);
            std::vector<RobotProgram> ans = HandleProgramRequest(req, worktime);
            ClientInterProcess::Get().AnswerProgramRequest(ans, worktime);
        }

        {
            double worktime;
            StrategyRequest req;
            ClientInterProcess::Get().ReceiveStrategyRequest(req);
            FactoryCommands ans = HandleStrategyRequest(req, worktime);
            ClientInterProcess::Get().AnswerStrategyRequest(ans, worktime);
        }

        if (pWorld->currentTime % 100 == 0)
            logprintf("%d cycles over\n", pWorld->currentTime);
    }

    return 0;
}
