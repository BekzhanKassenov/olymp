/**
 *
 * Answer for this test is "Draw"
 *
*/

#include "testlib.h"
#include <iostream>

using namespace std;

char grid[8][9] = {
                   "rnbqkbnr",
                   "pppppppp",
                   "........",
                   "........",
                   "........",
                   "........",
                   "PPPPPPPP",
                   "RNBQKBNR"
                  };

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    for (int i = 0; i < 8; i++) {
        cout << grid[i] << endl;
    }

    return 0;
}