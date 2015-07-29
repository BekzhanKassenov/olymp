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

int n;

bool ok(const vector <int> &a) {
	for (size_t i = 0; i < a.size(); i++)
		if (a[i] != (int)i)
			return false;

   	return true;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	cin >> n;

	vector <int> a(n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		a[i]--;
	}

	for (int i = 0; i < n; i++) {
		if (i != a[i]) {
			int l = i, r = a[i];

			if (a[r] == l) {
				
			}
		}
	}

	return 0;
}
