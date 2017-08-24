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
const int MAXN = 1100;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

char s[MAXN];
int k;
map <char, int> m;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    cin >> s >> k;

    int n = strlen(s);
    if (n < k) {
        cout << "impossible" << endl;
        return 0;
    }

    for (size_t i = 0; s[i]; i++) {
        m[s[i]]++;
    }

    int cur = m.size();
    int ans = 0;
    for (auto& p : m) {
        while (p.second > 1 && cur < k) {
            p.second--;
            cur++;
            ans++;
        }
    }

    cout << ans << endl;

    
    return 0;
}
