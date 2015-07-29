#ifndef WSO13_TIME_BALANCE_349165
#define WSO13_TIME_BALANCE_349165

#include <memory>

typedef void *TimedFunctionParameter;
typedef int (*TimedFunctionPointer)(TimedFunctionParameter);

static const double INFINITE_TIME = 1e+100;

class Timing {
    double softBalance;
    double softTL;  //avg per cycle
    double hardTL;  //max for one call
public:
    struct Data;
    static const int BAD_RETURN_VALUE = 0xDEADBEEF;
private:
    static std::auto_ptr<volatile Data> data;

public:
    Timing(double soft, double hard, double initialBalance = 0.0);

    bool AllowedToRun() const;
    void PassCycle();

    //returns false iff hard TLE
    bool Run(TimedFunctionPointer function, TimedFunctionParameter parameter, int &returnValue, bool accountTimeManually = false);
    //for the case when runtime is measured remotely
    void AccountTime(double worktime);
};

#endif
