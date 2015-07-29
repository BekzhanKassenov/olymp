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

string s, t, it;

int dp[110][110], len[110][110];
string res[110][110];

int calc(int a, int b) {
	if (a == 0 || b == 0)
		return 0;

	if (dp[a][b] != -1)
		return dp[a][b];

   	if (s[a - 1] == t[b - 1]) {
   		dp[a][b] = calc(a - 1, b - 1) + 1;
   		res[a][b] = res[a - 1][b - 1] + s[a - 1];
   		return dp[a][b];
   	}

   	int t1 = calc(a - 1, b), t2 = calc(a, b - 1);

   	if (t1 > t2) {
   		dp[a][b] = t1;
   		res[a][b] = res[a - 1][b];
   	} else {
   		dp[a][b] = t2;
   		res[a][b] = res[a][b - 1];
   	}

   	return dp[a][b];
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	getline(cin, s);
	getline(cin, t);
	getline(cin, it);
	memset(dp, -1, sizeof dp);

	calc(s.size(), t.size());

	cout << res[s.size()][t.size()] << endl;

	return 0;
}
