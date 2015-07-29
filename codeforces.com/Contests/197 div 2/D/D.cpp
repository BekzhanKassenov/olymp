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

int a[20][1 << 18], n, m, c, x, p;

void build(int l) {
	for (int i = 0; i < (1 << (c - l)); i++)
		if (l & 1)
			a[l][i] = (a[l - 1][i << 1] | a[l - 1][(i << 1) + 1]);
		else	
			a[l][i] = (a[l - 1][i << 1] ^ a[l - 1][(i << 1) + 1]);

   	if (l < c)
   		build(l + 1);
}                             

void upd(int lv, int pos) {
	int i = pos >> 1;

 	if (lv & 1)
 		a[lv][i] = (a[lv - 1][i << 1] | a[lv - 1][(i << 1) + 1]);
 	else
 		a[lv][i] = (a[lv - 1][i << 1] ^ a[lv - 1][(i << 1) + 1]);

 	if (lv < c)
 		upd(lv + 1, i);
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	scanf("%d%d", &c, &m);

	n = (1 << c);

	for (int i = 0; i < n; i++)
		scanf("%d", &a[0][i]);

	build(1);

	for (int i = 0; i < m; i++) {
	 	scanf("%d%d", &p, &x);
	 	a[0][p - 1] = x;
	 	upd(1, p - 1);
	 	printf("%d\n", a[c][0]);
	}

	return 0;
}
