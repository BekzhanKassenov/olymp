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
const int MAXN = 70;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, k;
string val[MAXN];
string name[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    cin >> n >> k;

    for (int i = 1; i <= n - k + 1; i++) {
        cin >> val[i];
    }

    for (int i = 1; i <= n; i++) {
        if (i <= 26) {
            name[i] = " ";
            name[i][0] = 'A' + i - 1;
        } else {
            name[i] = "  ";
            name[i][0] = 'A';
            name[i][1] = 'a' + i - 26 - 1; 
        }
    }

    for (int i = 1; i <= n - k + 1; i++) {
        if (val[i] == "NO") {
            name[k + i - 1] = name[i];
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << name[i] << ' ';
    }
    cout << endl;

    return 0;
}
