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

	int  val =  inf;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				if (i != j && j != k && i!=k)
					val = min (val, g[i][j] + g[j][k] + g[i][k]);
	cout << val;
	return 0;
}
