#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int n = atoi(argv[1]);

    switch (n) {
        case 1:
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    cout << 'q';
                }

                cout << endl;
            }

            break;
        
        case 2:
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    cout << 'Q';
                }

                cout << endl;
            }

            break;

        case 3:
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 8; j++) {
                    cout << 'q';
                }

                cout << endl;
            }

            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 8; j++) {
                    cout << 'Q';
                }

                cout << endl;
            }

            break;

        default:
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    cout << 'q';
                }

                cout << endl;
            }

            break;
    }

    return 0;
}