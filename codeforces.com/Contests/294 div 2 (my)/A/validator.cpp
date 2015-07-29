#include "testlib.h"

using namespace std;

int main()
{
    registerValidation();
    
    for (int i = 0; i < 8; i++) {
        inf.readToken("[QRBNPKqrbnpk.]{8-8}", "s");
        inf.readEoln();
    }
    
    inf.readEof();

    return 0;
}