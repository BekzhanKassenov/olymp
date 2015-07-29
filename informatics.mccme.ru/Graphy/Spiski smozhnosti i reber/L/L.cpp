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
	vector <int> a(n);
	int x,y;
	for (int i = 0; i < m; i++)
		{	
			cin >> x >> y;
			x--;
			y--;
			a[x]++;
			a[y]++;
		}
	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';
	return 0;
}
