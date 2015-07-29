#include "Common\InterProcess.h"
#include "Common\Utils.h"
#include "Common\Point.h"
#include "Common\TimeMemoryLimits.h"
#include "Common\History.h"
#define WIN32_LEAN_AND_MEAN
#define PSAPI_VERSION 1
#include "windows.h"
#include "psapi.h"
#pragma comment(lib, "psapi.lib")

//yeah, default-initialize POD structs
#pragma warning(disable : 4345)

const char *MMF_NAME = "WSO13_WorldData";
const char *PIPE_NAME_PREFIX = "\\\\.\\pipe\\WSO13_Pipe";
const int TYPICAL_MESSAGE_SIZE = sizeof(FactoryCommands) + sizeof(ProgramRobotsRequest) + sizeof(RobotProgram) + 1024;
const double FULL_VICTORY_SCORE = 1000000.0;

const char *GetPipeName(DWORD processId) {
    static char buff[256];
    sprintf(buff, "%s%u", PIPE_NAME_PREFIX, processId);
    return buff;
}

template<class Data> bool WriteDataToPipe(HANDLE hPipe, const Data &data, const char *dataName) {
    DWORD wrote;
    BOOL ok = WriteFile(
        hPipe,
        &data, sizeof(data),
        &wrote,
        NULL
    );
    if (!ok || wrote != sizeof(data)) {
        logprintf("Cannot write %d bytes to pipe (%s)!\n", sizeof(data), dataName);
        PrintWinAPIError(true);
        return false;
    }
    return true;
}
template<class Data> bool ReadDataFromPipe(HANDLE hPipe, Data &data, const char *dataName) {
    DWORD read;
    BOOL ok = ReadFile(
        hPipe,
        &data, sizeof(data),
        &read,
        NULL
    );
    if (!ok || read != sizeof(data)) {
        logprintf("Cannot read %d bytes from pipe (%s)!\n", sizeof(data), dataName);
        PrintWinAPIError(true);
        return false;
    }
    return true;
}
class PipeReadWriteException : std::exception {};
#define WriteToPipe_Terminate(hPipe, data) if (!WriteDataToPipe(hPipe, data, #data)) Terminate();
#define ReadFromPipe_Terminate(hPipe, data) if (!ReadDataFromPipe(hPipe, data, #data)) Terminate();
#define WriteToPipe_Throw(hPipe, data) if (!WriteDataToPipe(hPipe, data, #data)) throw PipeReadWriteException();
#define ReadFromPipe_Throw(hPipe, data) if (!ReadDataFromPipe(hPipe, data, #data)) throw PipeReadWriteException();


struct ClientInfo {
    int score;
    bool isDisqualified;    //true if player's score is set to zero

    bool isDead;    //true if client is disconnected
    PROCESS_INFORMATION pinfo;
    HANDLE hPipe;

    std::vector<char> mainRobotProgram;
};
struct ServerInterProcess::Data {
    std::vector<ClientInfo> clients;

    HANDLE hMemoryMappedFile;
    void *ptrMappedMemory;
};

struct ClientInterProcess::Data {
    HANDLE hMemoryMappedFile;
    void *ptrMappedMemory;
    HANDLE hPipe;
};


ServerInterProcess::ServerInterProcess() {
    data.reset(new Data());
}
ServerInterProcess::~ServerInterProcess() {}
ServerInterProcess &ServerInterProcess::Get() {
    static ServerInterProcess obj;
    return obj;
};

ClientInterProcess::ClientInterProcess() {
    playerIdx = -1;
    data.reset(new Data());
}
ClientInterProcess::~ClientInterProcess() {}
ClientInterProcess &ClientInterProcess::Get() {
    static ClientInterProcess obj;
    return obj;
};


void ServerInterProcess::Terminate(bool gameover) {
    logprintf("Server terminated %s\n", (gameover ? "normally." : "prematurely!"));
    if (!data.get())
        exit(6666);

    double score[PLAYERS_COUNT] = {0.0};
    for (int i = 0; i < data->clients.size(); i++) {
        TerminateProcess(data->clients[i].pinfo.hProcess, 123);
        if (!data->clients[i].isDisqualified)
            score[i] = data->clients[i].score;
    }

    double sum = 0.0;
    for (int i = 0; i < PLAYERS_COUNT; i++)
        sum += score[i];
    if (sum > 0.1) {
        for (int i = 0; i < PLAYERS_COUNT; i++)
            score[i] *= FULL_VICTORY_SCORE / sum;
    }

    FILE *fscore = fopen("score.txt", "wt");
    if (!fscore)
        logprintf("Cannot open score file for writing!\n");
    else {
        for (int i = 0; i < PLAYERS_COUNT; i++) {
            if (i) fprintf(fscore, " ");
            fprintf(fscore, "%d", int(score[i] + 0.5));
        }
        fprintf(fscore, "\n");
        fclose(fscore);
    }
    
    HistoryWriter::Get().Close();

    exit(gameover ? 0 : 666);
}
void ServerInterProcess::DisconnectClient(int playerIdx, bool disqualify) {
    logprintf("Client (%d; %u) disconnected!\n", playerIdx, data->clients[playerIdx].pinfo.dwProcessId);
    TerminateProcess(data->clients[playerIdx].pinfo.hProcess, 357);
    data->clients[playerIdx].isDead = true;
    if (disqualify) {
        logprintf("Player %d is disqualified!\n", playerIdx);
        data->clients[playerIdx].isDisqualified = true;
    }
}

void ClientInterProcess::Terminate() {
    //TODO: send some info to server that "we are dead because of ..."
    logprintf("Client terminated prematurely!\n");
    exit(666);
}


void ServerInterProcess::LaunchClientProcess(int playerIdx, const char *commandLine) {
    logprintf("Launching client %d with command line \"%s\"...\n", playerIdx, commandLine);
    std::vector<char> cmd(commandLine, commandLine + strlen(commandLine) + 1);
    if (data->clients.size() <= playerIdx)
        data->clients.resize(playerIdx + 1);

	//hack
	int len = cmd.size();
	int spcPos;
	for (spcPos = 0; spcPos < len; spcPos++)
		if (cmd[spcPos] == ' ')
			break;
	if (spcPos == len) {
		logprintf("Lua file is not specified in client %d command line!\n", playerIdx);
		Terminate();
	}
	int dirPos;
	for (dirPos = spcPos; dirPos >= 0; dirPos--)
		if (cmd[dirPos] == '\\' || cmd[dirPos] == '/')
			break;
	std::vector<char> workDir;
	if (dirPos >= 0) {
		workDir.assign(cmd.begin(), cmd.begin() + dirPos);
		workDir.push_back(0);
	}
	if (!workDir.empty())
		logprintf("Client %d working directory is set to \"%s\"\n", playerIdx, &workDir[0]);

    STARTUPINFOA startupInfo;
    memset(&startupInfo, 0, sizeof(startupInfo));
    startupInfo.cb = sizeof(startupInfo);
    startupInfo.dwFlags = STARTF_USESHOWWINDOW;
    startupInfo.wShowWindow = SW_MINIMIZE;

    BOOL ok = CreateProcessA(
        NULL,
        &cmd[0],
        NULL, NULL,
        FALSE,
        CREATE_NEW_CONSOLE,
        NULL,
        workDir.empty() ? NULL : &workDir[0],
        &startupInfo,
        &data->clients[playerIdx].pinfo
    );
    if (!ok) {
        logprintf("Cannot create client process!\n");
        PrintWinAPIError(true);
        Terminate();
    }

    HANDLE hdl = CreateNamedPipeA(
        GetPipeName(data->clients[playerIdx].pinfo.dwProcessId),
        PIPE_ACCESS_DUPLEX,
        PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT,
        2,
        TYPICAL_MESSAGE_SIZE,
        TYPICAL_MESSAGE_SIZE,
        0,
        NULL
    );
    if (hdl == INVALID_HANDLE_VALUE) {
        logprintf("Cannot create pipe!\n");
        PrintWinAPIError(true);
        Terminate();
    }
    data->clients[playerIdx].hPipe = hdl;

    ok = ConnectNamedPipe(
        data->clients[playerIdx].hPipe,
        NULL
    );
    if (!ok && GetLastError() != ERROR_PIPE_CONNECTED) {
        logprintf("Nobody connects to pipe!\n");
        PrintWinAPIError(true);
        Terminate();
    }

    WriteToPipe_Terminate(data->clients[playerIdx].hPipe, playerIdx);

    size_t mainRobotProgramSize;
    ReadFromPipe_Terminate(data->clients[playerIdx].hPipe, mainRobotProgramSize);
    std::vector<char> mainRobotProgram(mainRobotProgramSize);
    DWORD read;
    ok = ReadFile(
        data->clients[playerIdx].hPipe,
        &mainRobotProgram[0], mainRobotProgramSize,
        &read,
        NULL
    );
    if (!ok || read != mainRobotProgramSize) {
        logprintf("Cannot read main robot program (%d bytes)!\n", mainRobotProgramSize);
        PrintWinAPIError(true);
        Terminate();
    }
    data->clients[playerIdx].mainRobotProgram = mainRobotProgram;

    data->clients[playerIdx].score = 0;
    data->clients[playerIdx].isDead = false;
    data->clients[playerIdx].isDisqualified = false;
}
const std::vector<char> &ServerInterProcess::GetMainRobotProgram(int player) const {
    return data->clients[player].mainRobotProgram;
}

void ClientInterProcess::Init() {
    HANDLE hdl = CreateFileA(
        GetPipeName(GetCurrentProcessId()),
        GENERIC_READ | GENERIC_WRITE,
        0,
        NULL,
        OPEN_EXISTING,
        0, 0
    );
    if (hdl == INVALID_HANDLE_VALUE) {
        logprintf("Cannot connect to pipe!\n");
        PrintWinAPIError(true);
        Terminate();
    }
    data->hPipe = hdl;

    ReadFromPipe_Terminate(data->hPipe, playerIdx);
}

void ClientInterProcess::SendMainRobotProgram(const std::vector<char> &mainRobotProgram) {
    WriteToPipe_Terminate(data->hPipe, mainRobotProgram.size());

    DWORD wrote;
    BOOL ok = WriteFile(
        data->hPipe,
        &mainRobotProgram[0], mainRobotProgram.size(),
        &wrote,
        NULL
    );
    if (!ok || wrote != mainRobotProgram.size()) {
        logprintf("Cannot write main robot program (%d bytes)!\n", mainRobotProgram.size());
        PrintWinAPIError(true);
        Terminate();
    }
}

WorldData *ServerInterProcess::AllocateWorldData() {
    HANDLE hdl = CreateFileMappingA(
        INVALID_HANDLE_VALUE,
        NULL,
        PAGE_READWRITE | SEC_COMMIT,
        0,
        sizeof(WorldData),
        MMF_NAME
    );
    if (hdl == NULL || GetLastError() == ERROR_ALREADY_EXISTS) {
        logprintf("Cannot create file mapping!\n");
        PrintWinAPIError(true);
        Terminate();
    }
    data->hMemoryMappedFile = hdl;

    LPVOID ptr = MapViewOfFile(
        data->hMemoryMappedFile,
        FILE_MAP_ALL_ACCESS,
        0, 0, sizeof(WorldData)
    );
    if (ptr == NULL) {
        logprintf("Cannot map view of file!\n");
        PrintWinAPIError(true);
        Terminate();
    }
    data->ptrMappedMemory = ptr;

    WorldData *pWorld = new(ptr) WorldData();
    return pWorld;
}

const WorldData *ClientInterProcess::GetWorldData() {
    HANDLE hdl = OpenFileMappingA(
        FILE_MAP_READ,
        FALSE,
        MMF_NAME
    );
    if (hdl == NULL) {
        logprintf("Cannot open file mapping!\n");
        PrintWinAPIError(true);
        Terminate();
    }
    data->hMemoryMappedFile = hdl;

    LPVOID ptr = MapViewOfFile(
        data->hMemoryMappedFile,
        FILE_MAP_READ,
        0, 0, sizeof(WorldData)
    );
    if (ptr == NULL) {
        logprintf("Cannot map view of file!\n");
        PrintWinAPIError(true);
        Terminate();
    }
    data->ptrMappedMemory = ptr;

    return (const WorldData*) ptr;
}

void ServerInterProcess::SendWorld(int player) {
    //MMF is physically the same pages => no synchronization is necessary
}
void ClientInterProcess::ReceiveWorld() {
    //no sync is necessary
}

double ServerInterProcess::SendProgramRequest(int player, const ProgramRobotsRequest &programRobotsRequest, std::vector<RobotProgram> &programRobotsAnswer) {
    double programRobotsTime = 0.0;

    if (!data->clients[player].isDead) {
        try {
            WriteToPipe_Throw(data->clients[player].hPipe, programRobotsRequest);

            programRobotsAnswer.clear();
            for (int i = 0; i < programRobotsRequest.robotsCount; i++) {
                RobotProgram robotProgram;
                ReadFromPipe_Throw(data->clients[player].hPipe, robotProgram);
                programRobotsAnswer.push_back(robotProgram);
            }

            ReadFromPipe_Throw(data->clients[player].hPipe, programRobotsTime);
        }
        catch(...) {
            DisconnectClient(player);
        }
    }
    if (data->clients[player].isDead) {
        programRobotsAnswer.clear();
        //by default we'll build robots without any initialization
        for (int i = 0; i < programRobotsRequest.robotsCount; i++) {
            RobotProgram prog;
            prog.robotId = programRobotsRequest.robotId[i];
            prog.stringStart = prog.stringEnd = prog.scriptStart = prog.scriptEnd = 0;
            programRobotsAnswer.push_back(prog);
        }
    }

    return programRobotsTime;
}

void ClientInterProcess::ReceiveProgramRequest(ProgramRobotsRequest &programRobotsRequest) {
    ReadFromPipe_Terminate(data->hPipe, programRobotsRequest);
}

void ClientInterProcess::AnswerProgramRequest(const std::vector<RobotProgram>& programRobotsAnswer, double programRobotsTime) {
    for (int i = 0; i < programRobotsAnswer.size(); i++)
        WriteToPipe_Terminate(data->hPipe, programRobotsAnswer[i]);
    WriteToPipe_Terminate(data->hPipe, programRobotsTime);
}

double ServerInterProcess::SendStrategyRequest(int player, const StrategyRequest &strategyRequest, FactoryCommands &strategyAnswer) {
    double strategyTime = 0.0;

    if (!data->clients[player].isDead) {
        try {
            WriteToPipe_Throw(data->clients[player].hPipe, strategyRequest);

            ReadFromPipe_Throw(data->clients[player].hPipe, strategyAnswer);
            ReadFromPipe_Throw(data->clients[player].hPipe, strategyTime);
        }
        catch(...) {
            DisconnectClient(player);
        }
    }
    if (data->clients[player].isDead)
        strategyAnswer.commandsCount = 0;

    return strategyTime;
}

void ClientInterProcess::ReceiveStrategyRequest(StrategyRequest &strategyRequest) {
    ReadFromPipe_Terminate(data->hPipe, strategyRequest);
}

void ClientInterProcess::AnswerStrategyRequest(const FactoryCommands &strategyAnswer, double strategyTime) {
    WriteToPipe_Terminate(data->hPipe, strategyAnswer);
    WriteToPipe_Terminate(data->hPipe, strategyTime);
}

void ServerInterProcess::SetCurrentScore(int player, int score) {
    data->clients[player].score = score;
}

bool ServerInterProcess::CheckMemoryLimit(int player) {
    if (data->clients[player].isDead)
        return true;

	PROCESS_MEMORY_COUNTERS pmc;	//Чтобы узнать о памяти
    BOOL ok = GetProcessMemoryInfo(data->clients[player].pinfo.hProcess, &pmc, sizeof(pmc));
    if (!ok) {
        logprintf("Cannot check memory usage of client %d!\n", player);
        PrintWinAPIError(true);
        return true;    //no crime unless caught
    }
    if (pmc.PeakPagefileUsage > CLIENT_MEMORY_LIMIT)
        return false;
    return true;
}