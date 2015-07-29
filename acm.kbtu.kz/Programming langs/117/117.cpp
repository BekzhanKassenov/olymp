#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define int long long

main()
{
	int n;
	cin >> n;
	
	vector <vector <int> > g(n, vector <int> (n));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> g[i][j];

	vector <int> t(n);

	vector <int> ans;

	int cnt = 1000000;

	for (int i = 0; i < n; i++)
		t[i] = i;

  	do
  		{
  			int v = 0;

  			bool flag = true;

  			for (int i = 0; i < n - 1; i++)
  				{
  					if (g[t[i]][t[i + 1]] == 0)
  						{
  							flag = false;
  							break;
  						}
  					
  					v += g[t[i]][t[i + 1]];
  				}
  			
  			if (g[t[n - 1]][t[0]] != 0)
  				v += g[t[n - 1]][t[0]];
  			else
  				flag = false;

  			if (!flag)
  				continue;

  			if (v < cnt)
  				{
  					cnt = v;
  					ans = t;
  				}
  		}
  	while (next_permutation(t.begin(), t.end()));

  	ans.push_back(ans[0]);

  	for (int i = 0; i <= n; i++)
  		cout << ans[i] + 1 << ' ';

  	//cout << cnt;
}
