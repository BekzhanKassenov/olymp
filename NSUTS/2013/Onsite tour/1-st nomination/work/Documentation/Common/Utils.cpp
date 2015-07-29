#include "Common\Utils.h"
#include <cstdio>
#include <cstdlib>
#include <map>
#define WIN32_LEAN_AND_MEAN
#include "windows.h"

FILE *logFile = 0;
double timerMultiplier;

char logFileName[256] = "log.txt";
void SetLogFileName(const char *filename) {
    strcpy(logFileName, filename);
    if (logFile) {
        fclose(logFile);
        logFile = 0;
    }
    logFile = fopen(logFileName, "wt");
}

struct UtilsInitializer {
    UtilsInitializer() {
        LARGE_INTEGER counter, freq;
        if (!QueryPerformanceFrequency(&freq) || !QueryPerformanceCounter(&counter)) {
            logprintf("Cannot use high resolution timer!\n");
            exit(123);
        }
        timerMultiplier = 1.0 / freq.QuadPart;
    }
};
UtilsInitializer initializer;


int StringHashFunction(const char *s) {
    static const int BASE = 31;
    int res = 0;
    for (; *s; s++) res = res * BASE + (*s);
    return res;
}

static std::map<int, int> messagePrintCount;
void logvprintf(const char *format, va_list args) {
    //open file if necessary
    if (!logFile)
        logFile = fopen(logFileName, "wt");
    //check how many times this message has been posted
    int hash = StringHashFunction(format);
    int &cnt = messagePrintCount[hash];
    cnt++;
    //print message
    if (cnt <= LOG_MAX_MESSAGE_COUNT) {
        vfprintf(logFile, format, args);
        fflush(logFile);
    }
    //say about message suppression
    if (cnt == LOG_MAX_MESSAGE_COUNT)
        logprintf("Too many messages of this type. They will be suppressed in future.\n");
}
void logprintf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    logvprintf(format, args);
    va_end(args);
}

double GetTime() {
    LARGE_INTEGER val;
    QueryPerformanceCounter(&val);
    return timerMultiplier * val.QuadPart;
}

bool PrintWinAPIError(bool alwaysprint) {
    DWORD err = GetLastError();
    if (err == 0) {
        if (alwaysprint)
            logprintf("WinAPI error: none\n");
        return false;
    }

    char buffer[1024];
    DWORD len = FormatMessageA(
        FORMAT_MESSAGE_FROM_SYSTEM |
        FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        err,
        MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US),
        buffer, sizeof(buffer),
        NULL
    );

    logprintf("WinAPI error: %u, meaning:\n%s", err, buffer);
    return true;
}

bool unlimitedMode = false;
void EnableUnlimitedMode() {
    unlimitedMode = true;
}
bool IsUnlimitedMode() {
    return unlimitedMode;
}
