#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector <vector <vector <int> > > g;

int n;

void init()
{
	g.resize(n, vector <vector <int> >(n, vector <int>(n)));
}

int sum(int x, int y, int z)
{
	int ans = 0;
	for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
		for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
			for (int k = z; k >= 0; k = (k & (k + 1)) - 1)
				ans += g[i][j][k];

	return ans;
}

void upd(int x, int y, int z, int c)
{
	for (int i = x; i < n; i |= i + 1)
		for (int j = y; j < n; j |= j + 1)
			for (int k = z; k < n; k |= k + 1)
				g[i][j][k] += c;
}

int sum(int x, int y, int z, int _x, int _y, int _z) 
{
	int ans = 0;

	ans = sum(_x, _y, _z);

	ans -= sum(x - 1, _y, _z);

	ans -= sum(_x, y - 1, _z);

	ans -= sum(_x, _y, z - 1);

	ans += sum(x - 1, y - 1, _z);

	ans += sum(x - 1, _y, z - 1);

	ans += sum(_x, y - 1, z - 1);

	ans -= sum(x - 1, y - 1, z - 1);

	return ans;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	cin >> n;

	init();

	for (;;)
		{
			int tmp;

			cin >> tmp;

			if (tmp == 3)
				break;

			if (tmp == 1)
				{
					int x, y, z, k;

					cin >> x >> y >> z >> k;

					upd(x, y, z, k);
				}
				
			if (tmp == 2)
				{
					int x, y, z, _x, _y, _z;

					cin >> x >> y >> z >> _x >> _y >> _z;

					cout << sum(x, y, z, _x, _y, _z) << endl;
				}	
		}

	return 0;	
}
