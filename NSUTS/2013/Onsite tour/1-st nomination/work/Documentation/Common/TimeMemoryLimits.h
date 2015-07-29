#ifndef WSO13_TIME_MEMORY_LIMITS_051936
#define WSO13_TIME_MEMORY_LIMITS_051936

//all time limits in seconds

static const double ROBOT_THINK_TL_SOFT = 5e-3;
static const double ROBOT_THINK_TL_HARD = 3.0;

static const double ROBOT_INIT_TL_SOFT = 1e-3;
static const double ROBOT_INIT_TL_HARD = 3.0;

static const double STRATEGY_TL_SOFT = 1e-3;
static const double STRATEGY_TL_HARD = 3.0;
static const double STRATEGY_START_BALANCE = 0.5;

static const double PROGRAM_TL_SOFT = 1e-3;
static const double PROGRAM_TL_HARD = 3.0;
static const double PROGRAM_START_BALANCE = 0.5;

//all memory limits in bytes

static const int CLIENT_MEMORY_LIMIT = (256 + 32) << 20;
static const int ROBOTS_MEMORY_LIMIT = (256 + 32) << 20;
static const int ROBOT_MEMORY_REQUIRED_FOR_INIT = 1 << 20;

//log file size limit, also in bytes

static const int HISTORY_SIZE_LIMIT_PER_CYCLE = 10000;

#endif
