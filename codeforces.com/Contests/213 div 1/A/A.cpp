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

template <typename T>
inline T sqr(T n) {
	return (n * n);
}

int cnt[100000];

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int a;
	string s;
	cin >> a >> s;

	int sum = 0;

	int len = s.size();

	for (int i = 0; i < len; i++) {
		sum = 0;

		for (int j = i; j < len; j++) {
			sum += s[j] - '0';
			cnt[sum]++;
		}
	}

	ll ans = 0;

	if (a == 0) {
		long long sm = len * 1ll * (len + 1) / 2;
		
		cout << 2 * cnt[0] * 1ll * sm - cnt[0] * 1ll * cnt[0] << endl;

		return 0;
	}

	for (int i = 1; i * i <= a; i++) {
		if (a % i == 0) {
			if (i >= (int)1e5 || (a / i) >= (int)1e5)
				continue;

			if (i * i == a) {
				ans += cnt[i] * 1ll * cnt[i];
			} else {
				ans += cnt[i] * 1ll * cnt[a / i] * 2;
			}
		}
	}

	cout << ans;

	return 0;
}
