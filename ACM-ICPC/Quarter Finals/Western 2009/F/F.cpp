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

char a[30][30];
int n, w, h;

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int t;

	cin >> t;

	while (t--) {
		cin >> h >> w >> n;

		memset(a, '.', sizeof a);

		bool flag = (n);

		for (int i = 1; i < h - 1 && flag; i ++) {
			for (int j = 1 + (i % 2 == 0); j < w - 1 && flag; j += 2) {
				a[i][j] = '#';
				n--;

				flag = n;
			}
		}

		if (n)
			cout << "Impossible" << endl;
		else
			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++)
					cout << a[i][j];	

				cout << endl;
			}
		cout << endl;	
	}

	return 0;
}
