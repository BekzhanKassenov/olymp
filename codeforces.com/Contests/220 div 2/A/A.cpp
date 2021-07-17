/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);

template <typename T>
inline T sqr(T n) {
	return (n * n);
}

int n, m, i, j, a, b;

int solve(int ti, int tj) {
    if (i == ti && j != tj) {
         if (i - a < 1 && i + a > n) {
            return INF;
         }
    }
    if (i != ti && j == tj) {
        if (j - b < 1 && j + b > m) {
            return INF;
        }
    }
    if (abs(i - ti) % a != 0 || abs(j - tj) % b != 0) {
        return INF;
    }
    int di = abs(i - ti) / a;
    int dj = abs(j - tj) / b;
    if (di % 2 != dj % 2) {
        return INF;
    }
    return max(di, dj);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif


	cin >> n >> m >> i >> j >> a >> b;

	int ans = min(
        min(solve(1, m), solve(n, 1)), 
        min(solve(n, m), solve(1, 1)));

	if (ans < INF)
		cout << ans << endl;
	else
		cout << "Poor Inna and pony!" << endl;

	return 0;
}
