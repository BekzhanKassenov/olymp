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

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, t1, t2;

	cin >> n >> t1 >> t2;
	
	int res = 0;

	bool s1 = true, s2 = true;
	int ans = 0;

	for (int i = 1; ;i++) {
		if (i % t1 == 0 && s1) {
		 	res++;
		 	s1 = false;
		}

		if (i % t2 == 0 && s2) {
			res++;
			s2 = false;
		}

		ans = i;

		if (res < n) {
			if (i % t1 == 0)
				s1 = true;

			if (i % t2 == 0)
				s2 = true;
		} else
			if (!s1 && !s2)
				break;
	}

	cout << res << ' ' << ans << endl;

	return 0;
}
