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
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	cin >> n;

	int a[7] = {0};

	int x;

	for (int i = 0; i < n; i++)  {
		cin >> x;
		if (x == 5 || x == 7) {
			cout << -1;
			return 0;
		}
		a[x]++;
	}

	stringstream res;

	while (a[1] && a[2] && a[4]) {
		res << 1 << ' ' << 2 << ' ' << 4 << endl;
		a[1]--, a[2]--, a[4]--;	
	}

	while (a[1] && a[3] && a[6]) {
		res << 1 << ' ' << 3 << ' ' << 6 << endl;
		a[1]--, a[3]--, a[6]--; 
	}

	while (a[1] && a[2] && a[6]) {
		res << 1 << ' ' << 2 << ' ' << 6 << endl;
		a[1]--, a[2]--, a[6]--;
	}

	for (int i = 0; i < 7; i++) {
		if (a[i] > 0) {
			cout << -1;
			return 0;
		}
	}

	cout << res.str();
	return 0;
}
