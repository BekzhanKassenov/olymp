/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;
set <string> a[2], comm;

bool win(const set <string>& a, const set <string>& b) {
    return a.size() > b.size();
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        a[0].emplace(s);
    }

    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        if (a[0].count(s)) {
            a[0].erase(s);
            comm.emplace(s);
        } else {
            a[1].emplace(s);
        }
    }

    if (comm.size() & 1) {
        if (!win(a[1], a[0])) {
            puts("YES");
        } else {
            puts("NO");
        }
    } else {
        if (win(a[0], a[1])) {
            puts("YES");
        } else {
            puts("NO");
        }
    }


    return 0;
}
