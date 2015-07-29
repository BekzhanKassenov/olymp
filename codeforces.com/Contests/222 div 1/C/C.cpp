/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))

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

const int maxn = 110;

int n, m, s[maxn], nmb, len;
char c;
vector <pair <int, PII> > act;
bool calced[maxn][maxn];
int mem[maxn][maxn];

int dfs(int pos, int hero_num) {
	if (calced[pos][hero_num])
		return mem[pos][hero_num];

	calced[pos][hero_num] = true;
	int& ans = mem[pos][hero_num];

	for (int i = 0; i < act[pos].S.F; i++) {
		ans += s[hero_num++];	
	}

	if (act[pos].F == 2)
		ans *= -1;

	if (pos == len - 1) {
		return ans;
	}

	int res = dfs(pos + 1, hero_num);

	for (int i = 1; i <= act[pos].S.S; i++) {
		int tmp = dfs(pos + 1, hero_num + i);

		if (act[pos].F == 1)
			res = max(res, tmp);
		else
			res = min(res, tmp);	
	}

	ans += res;

	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> s[i];

	sort(s, s + n);
	reverse(s, s + n);

	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> c >> nmb;

		if (act.empty() || act.back().F != nmb) {
			if (c == 'p')
				act.push_back(MP(nmb, MP(1, 0)));
			else
				act.push_back(MP(nmb, MP(0, 1)));	
		} else {
			if (c == 'p')
				act.back().S.F++;
			else
				act.back().S.S++;	
		}
	}

	len = act.size();

	cout << dfs(0, 0);

	return 0;
}
