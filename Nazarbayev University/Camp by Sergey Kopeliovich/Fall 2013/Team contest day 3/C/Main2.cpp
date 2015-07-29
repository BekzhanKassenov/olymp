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

void pause() {
	int k = 0;
	for (int i = 0; i < (int)1e8; i++) {
	 	k += sqrt(i);
	}
}

int main() {
	#ifdef Local
		freopen("in", "r", stdin);
	#endif

	int n, k;

	cin >> n >> k;	

	int x;
	int cnt = 0;
	int mi = INF, ma = 0;

	for (int i = 0; i < n; i++) {
		cin >> x;
		mi = min(mi, x);
		ma = max(ma, x);
		if (a[x + 1500] == 0)
			cnt++;

		a[x + 1500]++;
	}

	if (cnt >= k) {
		cout << 0;
		return 0;
	}

	int len = n - cnt;

	int ans = 0;

	for (int i = mi + 1500 - len; i <= ma + 1501; i++) {
		int left = mi + 1500;

		int q[3000];

		for (int r = 0; r < 3000; r++)
			q[r] = a[r];

		int l = i;
		int cur = 0;

		for (int j = 0; j < len; j++) {
			while (a[left] <= 1 && left < 3000 - 1)
				left++;
	        while (a[left] > 1) {
	         	a[l]++;
	         	a[left]--;
	         	cur += abs(left - l);
	         	while (a[l] != 0) {
	         		l++;
	         	}
	        }
		}
		ans = max(ans, cur);

		for (int r = 0; r < 3000; r++)
			a[r] = q[r];
	}

	cout << ans;

	return 0;
}
