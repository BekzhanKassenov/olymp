#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector <int> g,tin,tout;

int timer = 0;
int n,m,a,b;

void dfs (int v)
{
	tin[v] = timer++;
	for (int i=1;i<=n;i++)
		if (g[i]==v)
			dfs(i);
	tout[v] = timer++;
}

int main()
{
	cin >> n;
	g.resize(n+2);
	tin.resize(n+2);
	tout.resize(n+2);
	int predok = 0;
	for (int i=1;i<=n;i++)
		{
			cin >> g[i];
			if (g[i]==0)
				predok = i;
		}
	dfs(predok);
	cin >> m;
	for (int i=0;i<m;i++)
		{
			cin >> a >> b;
			if (tin[a]<tin[b] && tout[a]>tout[b])
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
	return 0;
}
