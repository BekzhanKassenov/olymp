#include "testlib.h"
#include <iostream>

using namespace std;

char name[6] = {'Q', 'R', 'B', 'N', 'P', 'K'};
char weight[6] = {9, 5, 3, 3, 1, 0};

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    char figure = 'q';
    char other_pawn = 'P';
    int cnt = 0;

    if (argc >= 3) {
        figure = argv[1][0];
        
        if (isupper(figure)) {
            other_pawn = 'p';
        }

        cnt = atoi(argv[2]);
    }

    for (int i = 0; i < 5; i++) {
        if (name[i] == toupper(figure)) {
            cnt += weight[i];
        }
    }

    string s;
    s.append(1, figure);
    s.append(7, '.');

    cout << s << endl;

    int lnum = 1;

    while (cnt > 0) {
        s.clear();
        int k = 8;

        if (k > cnt) {
            k = cnt;
        }

        s.append(k, other_pawn);
        s.append(8 - k, '.');
        cnt -= k;

        cout << s << endl;
        lnum++;
    }
    
    s.clear();
    s.append(8, '.');

    for (int i = lnum; i < 8; i++) {
        cout << s << endl;
    }

    return 0;
}