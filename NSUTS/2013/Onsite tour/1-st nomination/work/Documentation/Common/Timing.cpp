#include "Common\Timing.h"
#include "Common\Utils.h"
#define WIN32_LEAN_AND_MEAN
#include "windows.h"


DWORD WINAPI WorkerIdleThread(LPVOID param);

struct Timing::Data {
    volatile HANDLE hStartEvent, hEndEvent;
    volatile HANDLE hExecuterThread;
    volatile TimedFunctionPointer function;
    volatile TimedFunctionParameter parameter;
    volatile int returnValue;

    Data() {
        hStartEvent = CreateEvent(0, false, false, 0);
        hEndEvent = CreateEvent(0, false, false, 0);
        hExecuterThread = CreateThread(0, 0, WorkerIdleThread, this, 0, 0);
        function = 0;
        parameter = 0;
    }
    ~Data() {
        TerminateThread(hExecuterThread, 365);
        CloseHandle(hExecuterThread);
        CloseHandle(hStartEvent);
        CloseHandle(hEndEvent);
    }
};
std::auto_ptr<volatile Timing::Data> Timing::data;

DWORD WINAPI WorkerIdleThread(LPVOID param) {
    volatile Timing::Data *ptr = (Timing::Data *)param;
	while (1) {
        WaitForSingleObject(ptr->hStartEvent, INFINITE);
		ptr->returnValue = (ptr->function)(ptr->parameter);
		SetEvent(ptr->hEndEvent);
	}
}


Timing::Timing(double soft, double hard, double initialBalance) {
    if (IsUnlimitedMode()) {
        softTL = 0.0;
        hardTL = INFINITE_TIME;
        softBalance = INFINITE_TIME;
    }
    else {
        softTL = soft;
        hardTL = hard;
        softBalance = initialBalance;
    }
}

bool Timing::AllowedToRun() const {
    if (softBalance > 0)
        return true;
    return false;
}

void Timing::PassCycle() {
    softBalance += softTL;
}

static inline DWORD TimeToWinAPI(double time) {
    time *= 1000.0;
    return DWORD(min(time, INFINITE));
}

bool Timing::Run(TimedFunctionPointer function, TimedFunctionParameter parameter, int &returnValue, bool accountTimeManually) {
    //start executer thread if it is not alive
    if (!data.get())
        data.reset(new Data());

    //save info about what to run
    data->function = function;
    data->parameter = parameter;
    data->returnValue = BAD_RETURN_VALUE;

    //run the code
    double beginTime = GetTime();
    SetEvent(data->hStartEvent);
    //wait for the code to complete (max - for hard TL)
    DWORD res = WaitForSingleObject(data->hEndEvent, TimeToWinAPI(hardTL));
    //stop time measuring
    double elapsedTime = GetTime() - beginTime;

    //cleanup
    data->function = 0;
    data->parameter = 0;

    //in any case, soft balance is decreased (unless it is counted manually)
    if (!accountTimeManually)
        softBalance -= elapsedTime;
    //set return value
    returnValue = data->returnValue;

    //if run was successful, return
    if (res == WAIT_OBJECT_0)
        return true;

    //either TLE or something is wrong
    if (res == WAIT_FAILED)
        PrintWinAPIError(true);

    //kill thread
    data.reset();

    return false;
}

void Timing::AccountTime(double worktime) {
    softBalance -= worktime;
}
