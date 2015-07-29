/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair

typedef pair <int, int> PII;

int n;
PII a[1000], b[1000], aa, bb;
bool used[1000];

inline int operator * (const PII& a, const PII& b) {
	return (a.F * b.S - b.F * a.S);
}

inline PII operator - (const PII& a, const PII& b) {
	return MP(a.F - b.F, a.S - b.S);
}

inline bool lo(const PII &t, const PII &a1, const PII &b) {
	return ((a1 - t) * (b - t) < 0);
}

inline int fastAbs(int n) {
	return ((n ^ (n >> 31)) - (n >> 31));
}

inline int fastMax(int x, int y) {
 	return (((y - x) >> 31) & (x ^ y)) ^ y;
}

inline int S(int a1, int b1, int c1) {
	return fastAbs((a[b1] - a[a1]) * (a[c1] - a[a1]));
}

inline int read_int() {
  	char c;

  	bool flag = false;

  	do {
  		c = getchar();
  		if (c == '-')
  			flag = true;
  	} while (c < '0' || c > '9');

  	int res = 0;

  	do {
  	 	res = res * 10 + c - '0';
  	 	c = getchar();
  	} while (c >= '0' && c <= '9');

  	if (flag)
  		res *= -1;

  	return res;
}

inline void build() {
	int mx = 0;

	for (int i = 1; i < n; i++) {
		if (b[i].S < b[mx].S || (b[i].S == b[mx].S && b[i].F < b[mx].F))
			mx = i;
	}

	a[0] = b[mx];
	int g = mx;
	used[mx] = true;

	int cnt = 1;

	for (int i = 1; i < n; i++) {
		int tmp = -1;

		for (int j = 0; j < n; j++) {
			if (!used[j] || j == g) {
			 	if (tmp == -1 || (b[tmp] - b[mx]) * (b[j] - b[mx]) < 0)
			 		tmp = j;
			}
		}
		if (tmp == g)
			break;
		used[tmp] = true;
		a[i] = b[tmp];
		cnt++;
		mx = tmp;
	}

	n = cnt;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif
	
	n = read_int();

	for (int i = 0; i < n; i++) {
		b[i].F = read_int();
		b[i].S = read_int();
	}

	if (n > 20)
		build();
	else
		for (int i = 0; i < n; i++)
			a[i] = b[i];

	int res = 0;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
		    int mx = -1, mx1 = -1;

			for (int k = 0; k < n; k++) {
				if ((i ^ k) && (j ^ k)) {
					if (lo(a[i], a[j], a[k]))
						mx = fastMax(mx, (S(i, j, k)));
					else
						mx1 = fastMax(mx1, (S(i, j, k)));
				}
					
			}

			if ((mx ^ -1) && (mx1 ^ -1))
				res = fastMax(res, mx + mx1);
		}
	}

	printf("%.14lf", (res + .0) / 2);

	return 0;
}
