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
	vector <vector <int> > g(n, vector <int> (n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> g[i][j];

	int p1 = 0, p2 = 0, p3 = 0, val =  inf;
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				if (i != j && j != k && i != k && g[i][j] + g[j][k] + g[i][k] < val) {
					val = g[i][j] + g[j][k] + g[i][k];
					p1 = i + 1;
					p2 = j + 1;
					p3 = k + 1;
				}
	
	cout << p1 << ' ' << p2 << ' ' << p3;
	return 0;
}
