#include <iostream>
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
	vector <vector <int> >  g(n, vector <int> (n));
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> g[i][j];

	vector <int> d(n, inf);
	vector <bool> used(n, false);
	s--;
	f--;
	d[s] = 0;
	for (int i = 0; i < n; i++)
		{
			int v = -1;
			for (int j = 0; j < n; j++)
				if (!used[j] && (v==-1 || d[j] < d[v]))
					v = j;
		   used[v] = true;
		   for (int j = 0; j < n; j++)	
		   	if (v!=j && g[v][j] != -1)
		   		d[j] = min (d[j], d[v] + g[v][j]); 
		}
   if (d[f]!=inf)
   	cout << d[f];
   else
   	cout << -1;
}
