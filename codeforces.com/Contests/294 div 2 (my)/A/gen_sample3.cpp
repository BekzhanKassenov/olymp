/**
 *
 * Answer for this test is "Black"
 *
*/

#include "testlib.h"
#include <iostream>

using namespace std;

char grid[8][9] = {
                   "rppppppr",
                   "...k....",
                   "........",
                   "........",
                   "........",
                   "........",
                   "K...Q...",
                   "........"
                  };

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    for (int i = 0; i < 8; i++) {
        cout << grid[i] << endl;
    }

    return 0;
}