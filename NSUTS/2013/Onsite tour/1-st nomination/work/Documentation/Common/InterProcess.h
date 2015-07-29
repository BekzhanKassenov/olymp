#ifndef WSO13_INTERPROCESS_730615
#define WSO13_INTERPROCESS_730615

#include "Common\DataTypes.h"
#include "Common\TransferredData.h"
#include <vector>

class ServerInterProcess {
    struct Data;
    std::auto_ptr<Data> data;

    ServerInterProcess();
public:
    static ServerInterProcess &Get();
    ~ServerInterProcess();
    void Terminate(bool gameover = false);
    void DisconnectClient(int playerIdx, bool disqualify = false);

    WorldData *AllocateWorldData();
    void LaunchClientProcess(int player, const char *commandLine);
    const std::vector<char> &GetMainRobotProgram(int player) const;

    void SendWorld(int player);
    double SendProgramRequest(int player, const ProgramRobotsRequest &request, std::vector<RobotProgram> &answer);
    double SendStrategyRequest(int player, const StrategyRequest &request, FactoryCommands& answer);
    void SetCurrentScore(int player, int score);
    bool CheckMemoryLimit(int player);
};

class ClientInterProcess {
    struct Data;
    std::auto_ptr<Data> data;

    int playerIdx;
    ClientInterProcess();
public:
    ~ClientInterProcess();
    static ClientInterProcess &Get();
    void Terminate();

    void Init();
    void SendMainRobotProgram(const std::vector<char> &mainRobotProgram);
    const WorldData *GetWorldData();
    inline int GetPlayerIndex() const { return playerIdx; }

    void ReceiveWorld();
    void ReceiveProgramRequest(ProgramRobotsRequest &request);
    void AnswerProgramRequest(const std::vector<RobotProgram> &programs, double timeElapsed);
    void ReceiveStrategyRequest(StrategyRequest &request);
    void AnswerStrategyRequest(const FactoryCommands &answer, double timeElapsed);

};

#endif
