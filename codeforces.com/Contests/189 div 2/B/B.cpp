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

int n, t, a, b;

bool match[110][110];

vector <PII> v;
vector <bool> used;
int len;

bool can(PII a, PII b) {
 	return ((a.F < b.S && a.F > b.F) || (a.S < b.S && a.S > b.F));
}

bool dfs(int a, int b) {
	used[a] = true;
	
	if (a == b)
		return true;

	bool flag = false;
	
	for (int i = 0; i < len; i++)
		if (match[a][i] && !used[i])
			flag |= dfs(i, b);

   	return flag;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
	 	scanf("%d%d%d", &t, &a, &b);

	 	if (t == 1) {
	 		v.push_back(MP(a, b));

	 		len++;
	 		for (size_t i = 0; i < v.size() - 1; i++) {
	 			if (can(v[i], v.back()))
	 				match[i][len - 1] = true;

	 			if (can(v.back(), v[i]))
	 				match[len - 1][i] = true;
	 		}
	 	} else {
	 		a--, b--;
	 		used.assign(len, 0);

	 		if (dfs(a, b))
	 			puts("YES");
	 		else
	 			puts("NO");
	 	}
	}

	return 0;
}
