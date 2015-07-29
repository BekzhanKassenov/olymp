#include "testlib.h"
#include <iostream>

using namespace std;

const int N = 15;

char input[N][10] = {
                    "8",
                    "1 2",
                    "2 3",
                    "2 4",
                    "2 5",
                    "5 6",
                    "6 7",
                    "6 8",
                    "6",
                    "3 5",
                    "3 6",
                    "3 8",
                    "5 8",
                    "7 3",
                    "5 7"
                    };


int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    
    for (int i = 0; i < N; i++) {
        cout << input[i] << endl;
    }

    return 0;
}
