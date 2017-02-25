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
const int MAXN = 500010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
string s[MAXN];

int get_cnt(string& s, string& t) {
    if (s <= t) {
        return 0;
    }

    int pos = -1;
    for (int i = 1; i < (int)min(s.size(), t.size()); i++) {
        if (s[i] > t[i]) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        return s.size() - t.size();
    }

    return s.size() - pos;
}

int main() {
    ios_base::sync_with_stdio(false);

#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    for (int i = n - 2; i >= 0; i--) {
        int cnt = get_cnt(s[i], s[i + 1]);
        while (cnt > 0) {
            s[i].pop_back();
            cnt--;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << s[i] << endl;
    }

    return 0;
}
