#include "testlib.h"
#include <iostream>

using namespace std;

const int N = 22;

char input[N][10] = {
                     "15",
                     "1 2",
                     "1 3",
                     "1 4",
                     "2 5",
                     "2 6",
                     "2 7",
                     "5 8",
                     "6 9",
                     "9 14",
                     "14 15",
                     "7 10",
                     "4 13",
                     "3 11",
                     "3 12",
                     "6",
                     "10 15",
                     "13 12",
                     "2 15",
                     "8 4",
                     "15 12",
                     "6 13"
                    };


int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    
    for (int i = 0; i < N; i++) {
        cout << input[i] << endl;
    }

    return 0;
}
