/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>
#include <climits>
#include <bitset>
#include <iomanip>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define PB push_back
#define INF (int)(2e9)
#define EPS 1e-9
#define MOD (1000 * 1000 * 1000)
#define all (x) (x).begin(), (x).end()

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template <typename T> 
inline T abs(T n) {
	return (n < 0 ? -n : n);
}

template <typename T>
inline T sqr(T n) {
	return (n * n);
}

long long f[100000];

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio(false);

	int n, m;

	cin >> n >> m;

	vector <int> a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	f[0] = f[1] = 1;

	for (int i = 2; i < 100000; i++) {
		f[i] = (f[i - 1] + f[i - 2]) % MOD;
	}

	int t;

	for (int i = 0; i < m; i++) {
		cin >> t;

	 	switch (t) {
	 		case 1:
	 			int x, v;
	 			cin >> x >> v;
	 			a[x - 1] = v;
	 			break;
	 	   	case 2:
	 	   		long long ans = 0;
	 	   		int l, r;

	 	   		cin >> l >> r;

	 	   		r--, l--;

	 	   		for (int j = 0; j <= r - l; j++)
	 	   			ans = (ans + f[j] * a[l + j]) % MOD;

	 	   	   	cout << ans << endl;
	 	   	   	break;
		}	
	}

	return 0;
}
