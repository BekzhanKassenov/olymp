#include <iostream>
#include <cstdio>
#include <vector>

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
	int a,b;
	for (int i = 0; i < n; i++)
		{
			a = 0;
			b = 0;
			for (int j = 0; j < n; j++)
				{
					a += g[i][j];
					b += g[j][i];
				}
			cout << b << ' ' << a << endl;
		}
	return 0;
}
