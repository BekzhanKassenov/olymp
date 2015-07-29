#include "testlib.h"
#include <iostream>

using namespace std;

const int N = 7;

char input[N][10] = {
                     "4",
                     "1 2",
                     "2 3",
                     "2 4",
                     "2",
                     "1 2",
                     "1 3"
                    };


int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    
    for (int i = 0; i < N; i++) {
        cout << input[i] << endl;
    }

    return 0;
}
