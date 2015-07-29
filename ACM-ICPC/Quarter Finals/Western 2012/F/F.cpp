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
#define File "lan"

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
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);

	int n, m;

	cin >> n >> m;

	vector <PII> a(m);

	for (int i = 0; i < m; i++) {
		cin >> a[i].F;
		a[i].S = i;
	}
	
	sort(a.rbegin(), a.rend());

	if (a[0].F >= n) {
		cout << 1 << endl << a[0].S + 1;
		return 0;
	}

	if (m > 1 && a[0].F + a[1].F - 2 >= n) {
		cout << 2 << endl << a[0].S + 1 << ' ' << a[1].S + 1;
		return 0;  
	}

	if (m > 2) {
		int sum = a[0].F + a[1].F - 2;

		for (int i = 2; i < m; i++) {
			sum += a[i].F - 2;

			if (sum >= n) {
				cout << i + 1 << endl;

				for (int j = 0; j <= i; j++) {
					cout << a[j].S + 1 << ' ';
				}
				return 0;
			}
		}
	}

	cout << "Epic fail";

	return 0;
}
