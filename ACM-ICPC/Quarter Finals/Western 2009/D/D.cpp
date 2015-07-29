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

const int maxn = 1000010;

int a[maxn];

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int t, n;

	scanf("%d", &t);

	while (t--) {
		scanf("%d", &n);

		for (int i = 0; i < n; i++) 
			scanf("%d", &a[i]);

		int dales = 0, hills = 0;

		for (int i = 1; i < n - 1; i++) {
			if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
				int ptr = i;

				while (ptr > 0 && a[ptr] > a[ptr - 1])
					ptr--;

				int ptr1 = i;

				while (ptr1 < n - 1 && a[ptr1] > a[ptr1 + 1])
					ptr1++;

				hills = max(hills, min(i - ptr, ptr1 - i));

			}
		}

		for (int i = 1; i < n - 1; i++) {
		 	if (a[i] < a[i - 1] && a[i] < a[i + 1]) {
		 		int ptr = i;

		 		while (ptr > 0 && a[ptr] < a[ptr - 1]) {
					ptr--;
				}

				int ptr1 = i;

				while (ptr1 < n - 1 && a[ptr1] < a[ptr1 + 1])
					ptr1++;

				dales = max(dales, min(i - ptr, ptr1 - i));

		 	}
		}

		printf("%d %d\n", hills, dales);

	}

	return 0;
}
                           