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

int n, q;
map <string, string> Map;
string str;
int ans;

bool check() {
    string s = str;

    while (s.size() > 1u) {
        string pref = s.substr(0, 2);
        if (Map.count(pref)) {
            s = Map[pref] + s.substr(2);
        } else {
            return false;
        }
    }

    return s == "a";
}

void go(int pos) {
    if (pos == n) {
        if (check()) {
            ans++;
        }

        return;
    }

    for (str[pos] = 'a'; str[pos] <= 'f'; str[pos]++) {
        go(pos + 1);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    cin >> n >> q;

    for (int i = 0; i < q; i++) {
        string s, t;
        cin >> s >> t;
        Map[s] = t;
    }

    str.resize(n);
    go(0);

    printf("%d\n", ans);

    return 0;
}
