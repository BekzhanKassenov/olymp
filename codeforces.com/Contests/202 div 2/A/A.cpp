/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset(x, y, sizeof(x))
#define y0 y0_lal
#define y1 y1_lal
#define yn en_lal
#define j0 j0_lal
#define j1 j1_lal
#define jn jn_lal
#define next next_lal
#define prev prev_lal

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

int n;

int x;

int cnt[3];

bool can(int n) {
	while (cnt[2] && n > 0) {
		n -= 100;
		cnt[2]--;
	}

	if (n < 0) {
		n += 100;
		cnt[2]++;
	}

	while (cnt[1] && n > 0) {
		n -= 50;
		cnt[1]--;
	}

	if (n < 0) {
		n += 50;
		cnt[1]++;
	}

	while (cnt[0] && n > 0) {
		n -= 25;
		cnt[0]--;
	}
	
	return (n == 0);
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	cin >> n;

	for (int i = 0; i < n; i++) {
	    cin >> x;

	    if (x == 25)
	    	cnt[0]++;

	    if (x == 50)
	    	cnt[1]++;

	  	if (x == 100)
	  		cnt[2]++;	

		int sd = x - 25;

		if (!can(sd)) {
			cout << "NO";
			return 0;
		}
	}

	cout << "YES";

	return 0;


	return 0;
}
