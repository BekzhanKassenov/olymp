#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,m;
	cin >> n >> m;
	vector <pair <int, int> > ans(n);
	int x,y;
	for (int i = 0; i < m; i++)
		{	
			cin >> x >> y;
			x--;
			y--;
			ans[x].first++;
			ans[y].second++;
		}
	for (int i = 0; i < n; i++)
		cout << ans[i].second << ' ' << ans[i].first << endl;
	return 0;
}
