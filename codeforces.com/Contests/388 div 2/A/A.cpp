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

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    cin >> n;

    vector <int> ans;

    if (n % 2 == 1) {
        ans.push_back(3);
        n -= 3;
    }

    while (n > 0) {
        ans.push_back(2);
        n -= 2;
    }

    cout << ans.size() << endl;
    for (int x : ans) {
        cout << x << ' ';
    }
    cout << endl;

    return 0;
}
