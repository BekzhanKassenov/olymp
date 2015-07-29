#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    cin >> s;

    int res = (int)1e9;

    for (int i = 0; i < 8; i++) {
        for (int j = i + 1; j < 8; j++) {
            for (int k = j + 1; k < 8; k++) {
                for (int l = k + 1; l < 8; l++) {
                    int num = (((s[i] - '0') * 10 + (s[j] - '0')) * 10 + (s[k] - '0')) * 10 + s[l] - '0';
                    res = min(res, num);
                }
            }
        }
    }

    cout << res << endl;
}
