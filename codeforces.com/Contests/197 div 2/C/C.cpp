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

bool can[11], flag;
int m, res[100010], sz;

bool ans[30][20][100010];

bool dfs(int bal, int last, int len) {
	if ((bal == 0 && last != -1) || ans[bal + 10][last][len])
		return false;

	ans[bal + 10][last][len] = true;	

	if (len == m)
		return true;

	for (int i = 1; i <= 10; i++) {
		if (can[i] && i != last) {
			int cur = bal;

			if (len & 1)
				cur -= i;
			else
				cur += i;

			if (abs(cur) <= 10)
				if ((((len & 1) && cur < 0) || (!(len & 1) && cur > 0)) && dfs(cur, i, len + 1)) {
					res[sz++] = i;
				return true;
			}
		}
	}
	return false;
}

stringstream ss;

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif
		
	string s;
	getline(cin, s);

	scanf("%d", &m);

	for (int i = 0; i < 10; i++)
		can[i + 1] = (s[i] == '1');

	if (dfs(0, -1, 0)) { 
		puts("YES");

		for (int i = sz - 1; i >= 0; i--)
			ss << res[i] << ' ';

		cout << ss.str();
	}
	else
		puts("NO");

	return 0;
}
