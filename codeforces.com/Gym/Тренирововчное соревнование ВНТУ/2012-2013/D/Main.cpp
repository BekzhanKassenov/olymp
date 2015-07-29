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
const int maxn = 100010;

template <typename T>
inline T sqr(T n) {
	return (n * n);
}

int a[maxn], incr[maxn], decr[4 * maxn], n, k;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	scanf("%d%d", &n, &k);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	incr[0] = 1;
	decr[0] = 1;

	for (int i = 1; i < n; i++) {
		if (a[i] >= a[i - 1])
			incr[i] = incr[i - 1] + 1;
		else
			incr[i] = 1;

		if (a[i] <= a[i - 1])
			decr[i] = decr[i - 1] + 1;
		else
			decr[i] = 1;	
	}

	//for (int i = 0; i <= 5; i++)
	//	cout << incr[i] << ' ' << decr[i] << endl;

	for (int i = 0; i < n; i++) {
		if (incr[i] >= k && decr[i + k] >= k) {
			puts("Mountains");
			return 0;
		}
	}

	puts("NoTibet");

	return 0;
}
