/****************************************
**          Solution by NU #2          **
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

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n, s, k;

    cin >> n >> k >> s;

    int best = max (1, s - k * (n - 1));
    int worst = min (k, s - n + 1);

    int best2;
    int worst2;

    if (s % n == 0) best2 = s / n, worst2 = s / n;
    else best2 = s / n, worst2 = best2 + 1;

    cout << best << " " << best2 << " " << worst2 << " " << worst;

    return 0;
}
