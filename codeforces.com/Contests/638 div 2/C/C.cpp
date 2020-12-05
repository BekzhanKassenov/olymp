/*****************************************
**     Solution by Bekzhan Kassenov     **
*****************************************/

#include <bits/stdc++.h>

using namespace std;

#define by(T, x) [](const T& a, const T& b) { return a.x < b.x; }
#define all(x) (x).begin(), (x).end()

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

const double EPS = 1e-9;
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int T;
int n, k;
string s;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    cin >> T;

    while (T--) {
        cin >> n >> k;
        cin >> s;
        sort(all(s));

        if (s[k - 1] != s[0]) {
            cout << s[k - 1] << endl;
            continue;
        }

        cout << s[0];
        if (s[k] == s[n - 1]) {
            int rem = n - k;
            int ans_len = (rem + k - 1) / k;
            for (int i = 0; i < ans_len; i++) {
                cout << s[k];
            }
        } else {
            cout << s.substr(k);
        }
        cout << endl;
    }
    
    return 0;
}
