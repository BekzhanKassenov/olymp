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

	VI a(n);

	for (int i = 0; i < n; i++)	
		cin >> a[i];

	sort(a.begin(), a.end());

	cout << a[n - 1] << ' ';

	for (int i = 1; i < n - 1; i++)
		cout << a[i] << ' ';

	cout << a[0] << endl;	

	return 0;
}
