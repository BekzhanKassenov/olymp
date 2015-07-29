/****************************************
**         Solution by NU_02           **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))
#define y0 y0asd
#define y1 y1asd
#define yn enasd
#define j0 j0asd
#define j1 j1asd
#define jn jnasd

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

int a[3000];

int main() {
	#ifdef Local
		freopen("in", "r", stdin);
	#endif

	int n, k;

	cin >> n >> k;	

	int x;
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		cin >> x;
		if (a[x + 1500] == 0)
			cnt++;

		a[x + 1500]++;
	}

	int ans = 0;

	while (cnt < k) {
		int minp = -1, minp1 = -1, mindist = INF;
		for (int i = 0; i < 3000; i++) {
			if (a[i])
				continue;

			int mind = INF, minpos = -1;

			for (int j = 0; j < 3000; j++) {
				if (a[j] > 1 && abs(i - j) < mind) {
				 	mind = abs(i - j);
				 	minpos = j;
				}
			}
			
			if (mind < mindist) {
				mindist = mind;
				minp = minpos;
				minp1 = i;
			}
		}
		//cout << minp - 1500 << ' ' << minp1 - 1500 << ' ' << a[minp] << ' ' << a[minp1] << endl;
		cnt++;
		a[minp1]++;
		a[minp]--;
		ans += mindist;
	}

	cout << ans;

	return 0;
}
