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
		for (int j = 0; j < n;j++)
			cin >> g[i][j];
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)	
			if (g[i][j] == 1)
				cout << i + 1 << ' ' << j + 1 << endl;
	return 0;
}
