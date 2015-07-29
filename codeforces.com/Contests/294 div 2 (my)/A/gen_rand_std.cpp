#include "testlib.h"
#include <iostream>

using namespace std;

char s[64] = "PPPPPPPPQKRRBBNNppppppppqkrrbbnn";

void shuffle(char s[], int len) {
    for (int i = 0; i < len; i++) {
        int pos = i + rnd.next(len - i);
        swap(s[i], s[pos]);
    }
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    shuffle(s, 32);
    int len = rnd.next(32);

    for (int i = len; i < 64; i++) {
        s[i] = '.';
    }

    shuffle(s, 64);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << s[i * 8 + j];
        }

        cout << endl;
    }

    return 0;
}