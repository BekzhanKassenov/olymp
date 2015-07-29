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
	vector <vector <int> > g(n, vector <int> (n,0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> g[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (g[i][j] != g[j][i] || (i==j && g[i][j] == 1))
				{
					cout << "NO";
					return 0;
				}
	cout << "YES";
	return 0;
}
