#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int maxn = 110;

vector <int> g[maxn], res[2];
vector <vector <int> > cmp;
vector <bool> used;

int color[maxn], n, m;

bool dfs(int v, int col, vector <int>& comp) {
	color[v] = col;
	comp.push_back(v);

	bool res = true;

	for (size_t i = 0; i < g[v].size() && res; i++) {
		if (!color[g[v][i]])
			res &= dfs(g[v][i], 3 - col, comp);
		else
			res &= (color[g[v][i]] != color[v]);
	}

	return res;
}   

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	cin >> n >> m;

	int a, b;

	for (int i = 0; i < m; i++) {
	 	cin >> a >> b;
	 	a--, b--;
	 	g[a].push_back(b);
	 	g[b].push_back(a);
	}

	bool can = true;
	vector <int> comp;

	for (int i = 0; i < 2 * n && can; i++) {
		if (!color[i]) {
		  	can &= dfs(i, 1, comp);
		  	cmp.push_back(comp);

		  	for (int j = 0; j < (int)comp.size(); j++)
		  		cout << comp[j] + 1 << ' ' ;

		  	cout << endl;	

		  	comp.clear();
		}
	}

	if (!can) {
		cout << "IMPOSSIBLE";
		return 0;
	}

	used.resize(cmp.size());

	for (size_t i = 0; i < cmp.size(); i++) {
		if (used[i])
			continue;

		used[i] = true;

		for (size_t j = 0; j < cmp[i].size(); j++) 
			res[color[cmp[i][j]] - 1].push_back(cmp[i][j] + 1);
		
		if (cmp[i].size() % 2 == 1) {
			for (size_t k = i + 1; k < cmp.size(); k++) {
				if (!used[k] && cmp[k].size() % 2 == 1) {
					used[k] = true;

					for (size_t j = 0; j < cmp[k].size(); j++) 
						res[!(color[cmp[k][j]] - 1)].push_back(cmp[k][j] + 1);
					
					break;
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
		cout << res[0][i] << ' ';

	cout << endl;

	for (int i = 0; i < n; i++)
		cout << res[1][i] << ' ';

	return 0;	
}
