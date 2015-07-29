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

int main() {
	#ifdef Local
		freopen("in", "r", stdin);
	#endif

	ios_base :: sync_with_stdio(false);

	int n, m;

	string s;

	while (cin >> n >> m && n && m) {
	 	map <string, int> m;
	 	for (int i = 0; i < n; i++) {
	 		cin >> s;
	 		m[s]++;
	 	}

	 	map <int, int> m1;
	 	for (map <string, int> :: iterator it = m.begin(); it != m.end(); it++)
	 		m1[it -> S]++;

	   	for (int i = 1; i <= n; i++)
	   		cout << m1[i] << endl;
	}

	return 0;
}
