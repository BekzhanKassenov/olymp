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

int n;
string s;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    cin >> n >> s;

    int pos = 0;
    string ans;
    while (pos < (int)s.size()) {
        if (pos + 3 <= (int)s.size() && s.substr(pos, 3) == "ogo") {
            pos += 3;
            while (pos + 2 <= (int)s.size() && s.substr(pos, 2) == "go") {
                pos += 2;
            }

            ans += "***";
        } else {
            ans += s[pos];
            pos++;
        }
    }

    cout << ans << endl;

    return 0;
}
