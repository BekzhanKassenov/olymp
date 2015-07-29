#ifndef WSO13_UTILS_306416
#define WSO13_UTILS_306416

#include <cstdarg>

//if some message appears too often, stop writing it (don't waste space in logs)
static const int LOG_MAX_MESSAGE_COUNT = 10000;

//set where the log resides (NOTE: must be called prior to any logprintf call)
void SetLogFileName(const char *filename);

//print some message to log file
void logprintf(const char *format, ...);
void logvprintf(const char *format, va_list args);

//for timing (uses QueryPerformanceCounter)
double GetTime();

//print to log the GetLastError() number and a message about it in english
bool PrintWinAPIError(bool alwaysprint = false);

//if this flag is set to true, then all time/memory limits are removed
void EnableUnlimitedMode();
bool IsUnlimitedMode();

#endif
