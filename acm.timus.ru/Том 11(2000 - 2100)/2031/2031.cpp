#include <iostream>
#include <cstdio>

using namespace std;

string arr[4] = {"16", "06", "68", "88"};

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    int n;
    cin >> n;
    if (n > 4) {
        cout << "Glupenky Pierre" << endl;
    } else {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << ' ';
        }
        cout << endl;
    }

    return 0;
}
