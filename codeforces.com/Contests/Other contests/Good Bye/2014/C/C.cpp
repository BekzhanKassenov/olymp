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
const int MAXN = 510;
const int MAXM = 1010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;
int w[MAXN], b[MAXM], prev[MAXN];
long long result;
bool used[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

	scanf("%d%d", &n, &m);

	for (int i = 1; i <= n; i++) {
	 	scanf("%d", &w[i]);
	}

	for (int i = 1; i <= m; i++) {
	 	scanf("%d", &b[i]);
	}

	for (int i = 1; i <= m; i++) {
        memset(used, false, sizeof used);

        for (int j = prev[b[i]] + 1; j < i; j++) {
         	if (!used[b[j]]) {
         		result += w[b[j]];
         		used[b[j]] = true;
         	}
        }

        prev[b[i]] = i;
	}

	printf("%I64d\n", result);
    return 0;
}
