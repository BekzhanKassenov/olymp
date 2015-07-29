#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int inf = 1000000000;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin >> n;
	vector <vector <int> > a(n + 1,vector <int> (n + 1, -1));
	int z;
	
	for (int i = 0; i < n; i++)
		for (int j = i + 1;j <= n; j++)
			cin >> a[i][j];
	
	vector <int> d(n+1,inf);
	
	d[0] = 0;

	for (int i = 0; i <= n; i++)
		{
			for (int j = i + 1; j <= n;j ++)
				d[j] = min (d[j], d[i] + a[i][j]);
		}
	cout << d[n];
	return 0; 
}
