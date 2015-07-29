#ifndef ONLINE_JUDGE
  #include "../testlib.h"
#else
  #include "testlib.h"
#endif

#include <iostream>

using namespace std;

string test[2] = {
                 "3 1",
                 "1 1 2"
                };

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    cout << test[0] << endl;
    cout << test[1] << endl;

    return 0;
}