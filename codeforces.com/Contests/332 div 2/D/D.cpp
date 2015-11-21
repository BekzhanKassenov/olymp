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

long long x;
vector <pair <long long, long long> > ans;

long long sumSquares(long long n) {
    return (n * (n + 1) * (2 * n + 1)) / 6;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    cin >> x;

    for (long long a = 1; sumSquares(a) <= x; a++) {
        long long b = x - sumSquares(a);

        long long sum = (a * (a + 1)) / 2;

        if (b % sum == 0) {
            b /= sum;

            b += a;

            ans.emplace_back(a, b);
            ans.emplace_back(b, a);
        }
    }

    sort(all(ans));
    ans.resize(unique(all(ans)) - ans.begin());

    cout << ans.size() << endl;
    for (const auto& p: ans) {
        cout << p.first << ' ' << p.second << endl;
    }

    return 0;
}
