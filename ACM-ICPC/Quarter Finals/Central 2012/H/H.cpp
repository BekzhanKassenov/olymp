/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define INF (int)(2e9)
#define EPS 1e-9
#define MOD (1000 * 1000 * 1000 + 7)
#define all(x) (x).begin(), (x).end()

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template <typename T>
inline T sqr(T n) {
	return (n * n);
}

int n, m;

int a[10010][300];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) {
    	scanf("%d", &a[i][0]);
    	a[i][a[i][0]]++;
    }

    for (int i = 2; i <= n; i++) {
    	for (int j = 1; j < 300; j++)
    		a[i][j] += a[i - 1][j];
    }

    int l, r, ans;

    for (int i = 0; i < m; i++) {
    	scanf("%d%d", &l, &r);

    	ans = 0;

    	for (int j = 1; j < 300; j++)
    		ans += (a[r][j] - a[l - 1][j] > 0);

    	printf("%d\n", ans);
    }

	return 0;
}
