#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;

#define all(x) (x).begin(), (x).end()

string get_min(int n) {
    string res;

    for (int i = min(9, n); i >= 2 && n > 1; i--) {
        while (n % i == 0) {
            res += char('0' + i);
            n /= i;
        }
    }

    reverse(all(res));

    if (n > 1)
        res = "-1";

    return res;
}

string get_max(int n) {
    string res;

    for (int i = 2; i <= min(9, n) && n > 1; i++) {
        while (n % i == 0) {
            res += char('0' + i);
            n /= i;
        }
    }

    reverse(all(res));

    if (n > 1)
        res = "-1";

    return res;
}       

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    cout << get_min(n) << ' ' << get_max(n) << endl;

    return 0;
}
