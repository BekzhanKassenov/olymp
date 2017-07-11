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

int compare(const string& s, const string& t, int offset) {
    int ans = 0;
    for (size_t i = 0; i < s.size(); i++) {
        ans += s[i] != t[offset + i];
    }

    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    string t;
    cin >> t;

    int offset = 0, ans = compare(s, t, 0);
    for (int i = 1; i <= m - n; i++) {
        int c = compare(s, t, i);
        if (c < ans) {
            offset = i;
            ans = c;
        }
    }

    cout << ans << endl;
    for (int i = 0; i < n; i++) {
        if (s[i] != t[offset + i]) {
            cout << i + 1 << ' ';
        }
    }
 
    return 0;
}
