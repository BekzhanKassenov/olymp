#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

const int inf = 1000000000;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n, s, f;
	cin >> n >> s >> f;
	s--;
	f--;
	vector <vector <int> > g(n, vector <int> (n));
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> g[i][j];
	vector <int> d(n, inf);
	vector <bool> used(n, false);
	vector <int> p(n, -1);
	d[s] = 0;

	for (int i = 0; i < n; i++)
		{
			int v = -1;
			for (int j = 0; j < n; j++)
				if (!used[j] && (v == -1 || d[j] < d[v]))
					v = j;
			used[v] = true;
			for (int j = 0; j < n; j++)
				if (v != j && g[v][j]!=-1)
				    if (d[j] > d[v] + g[v][j])
				    	{
				    		p[j] = v;
				    		d[j] = d[v] + g[v][j];
				    	}
	   }
	if (d[f] == inf)
		cout << -1;
	else
		{
			vector <int> ans;
			ans.reserve(n);
			int v = f;
			while (v!=-1)
				{
					ans.push_back (v + 1);
					v = p[v];
				}
			reverse(ans.begin(), ans.end());
			for (int i = 0; i < ans.size(); i++)
				cout << ans[i] << ' ';
		}
	return 0;
}
