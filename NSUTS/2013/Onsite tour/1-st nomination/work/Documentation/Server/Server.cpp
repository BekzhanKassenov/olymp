#include "GameLogic\World.h"
#include "Common\InterProcess.h"
#include "Common\Utils.h"
#include "Common\History.h"
#include <assert.h>
#include <stdio.h>
#include <time.h>
#include <vector>
#include <string>

inline double getTime() { return clock() / double(CLOCKS_PER_SEC) * 1000; }
double startTime = getTime();

void Init(std::vector<std::string> clientCmds) {
    SetLogFileName("ServerLog.txt");
    HistoryWriter::Get().Init("History.bin");
    HistoryWriter::Get().WriteFrame(World::Get().GetData());
    for (size_t i = 0; i < clientCmds.size(); i++)
        ServerInterProcess::Get().LaunchClientProcess(i, clientCmds[i].c_str());
}
void Exit() {
    int cycles = World::Get().GetData()->currentTime;
    double deltaTime = (getTime() - startTime) / 1000.0;
    fprintf(stderr, "%d cycles modelled in %0.3lf seconds (%0.1lf fps)\n", cycles, deltaTime, cycles / (deltaTime + 1e-9));
    ServerInterProcess::Get().Terminate(true);
}

void Cycle(void) {
	static double lastfpscalc = getTime();
	static int thissecondcount = 0;
	static double fps = 0.0;
    //check if another second passed
    double newframe = getTime();
	if (newframe - lastfpscalc > 1000.0) {
        //calculate FPS
		fps = thissecondcount / (newframe - lastfpscalc) * 1000.0;
		thissecondcount = 0;
		lastfpscalc = newframe;
		//get living units count
    	int tcnt[4] = {0, World::Get().GetUnitsCount(1), World::Get().GetUnitsCount(2), World::Get().GetUnitsCount(3)};
        //print some message to stderr (to show that we are still alive=) )
    	fprintf(stderr,
            "FPS = %0.2lf   Time = %d   Score = %d vs %d   Entities = %d (%d:%d:%d)\n"
            , fps, World::Get().GetData()->currentTime
        	, World::Get().GetScore(0), World::Get().GetScore(1)
        	, tcnt[1]+tcnt[2]+tcnt[3], tcnt[1], tcnt[2], tcnt[3]
	    );
	}
	thissecondcount++;

    //perform game cycle
    bool gameover = World::Get().DoCycle();
    HistoryWriter::Get().WriteFrame(World::Get().GetData());
    if (gameover)
        Exit();
}

int main(int argc, char **argv) {
    std::vector<std::string> clientCmds;
    for (int i = 1; i<argc; i++) {
        if (strcmp(argv[i], "-d") == 0)
            EnableUnlimitedMode();
        else
            clientCmds.push_back(argv[i]);
    }
    if (clientCmds.size() != 2) {
        fprintf(stderr, "Specify exactly two client programs as parameters\n");
        return 135;
    }


    Init(clientCmds);
	while (1)
        Cycle();
}
