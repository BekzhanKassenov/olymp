#include <iostream>

using namespace std;

int main() {
    cout << 1000 << endl;

    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            cout << 1;
        }
        cout << endl;
    }

    return 0;
}