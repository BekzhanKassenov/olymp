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
#include <iomanip>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define PB push_back
#define INF (int)(2e9)
#define MOD (1000 * 1000 * 1000 + 7)

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;

template <typename T> 
T abs(T n) {
	return (n < 0 ? -n : n);
}

template <typename T>
T sqr(T n) {
	return (n * n);
}

template <typename T>
T max(T a, T b) {
	return (a > b ? a : b);
}

template <typename T>
T min(T a, T b) {
	return (a < b ? a : b);
}

VVI g;

vector <bool> used;

void dfs(int v, vector <int>& cmp) {
	used[v] = true;
	cmp.PB(v);

	for (size_t i = 0; i < g[v].size(); i++)
		if (!used[g[v][i]])
			dfs(g[v][i], cmp);

}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n, m;

	cin >> n >> m;

	g.resize(n);
	used.resize(n, false);

	int x, y;

	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		x--, y--;
		g[x].PB(y);
		g[y].PB(x);
	}

	VVI cmps;

	VI cmp, od;

	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			cmp.clear();
			dfs(i, cmp);
			if (cmp.size() > 3) {
				cout << -1;
				return 0;
			}

			if (cmp.size() == 1) {
				od.PB(i);
			} else 
				if (!cmp.empty())
					cmps.PB(cmp);
		}
	}

	for (size_t i = 0; i < cmps.size(); i++) {
		if (cmps[i].size() == 2) {
			if (od.empty()) {
				cout << -1;
				return 0;
			}

			cmps[i].PB(od.back());
			od.pop_back();
		}
	}

	for (size_t i = 0; i < cmps.size(); i++)
		cout << cmps[i][0] + 1 << ' ' << cmps[i][1] + 1 << ' ' << cmps[i][2] + 1 << endl;

	while (!od.empty()) {
		for (int i = 0; i < 3; i++) {
			cout << od.back() + 1 << ' ';
			od.pop_back();
		}
		cout << endl;
	}	

	return 0;
}
