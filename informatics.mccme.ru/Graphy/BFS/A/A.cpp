#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin >> n;
	vector <vector <int> > g(n, vector <int> (n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> g[i][j];

	vector <int> d(n, 1000);
	vector <bool> used(n, false);
	vector <int> p(n, -1);
	int s,t;
	cin >> s >> t;
	s--;
	t--;
	d[s] = 0;
	used[s] = true;

	queue <int> q;
	q.push(s);
	
	while(!q.empty())
		{
			int v = q.front();
			q.pop();
			for (int i = 0; i < n; i++)
				if (g[v][i] && !used[i])
					{
						q.push(i);
						p[i] = v;
						used[i] = true;
						d[i] = min(d[i], d[v] + 1);
					} 
		}
	if (d[t] != 1000)
		{
			cout << d[t] << endl;
			vector <int> ans;
			for (int i = t; i != -1; i = p[i])
				ans.push_back(i + 1);
			reverse(ans.begin(), ans.end());
			for (int i = 0; i < ans.size(); i++)
				cout << ans[i] << ' ';
		}
	else
		cout << -1;
	return 0;
}
