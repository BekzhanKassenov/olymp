#include "Common/DataTypes.h"
#include <map>
#include <string>

extern const WorldData *pWorld;
extern int playerIndex;

std::map<int, int> Strategy();
std::pair<std::string, std::string> Program(int robotIndex);

//for adapter errors only!
void logprintf(const char *format, ...);

