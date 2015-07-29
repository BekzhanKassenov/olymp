#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

int n, m, y;

int pwr(int a, int b)
{
	int ans = 1;

	for (int i = 1; i <= b; i++)
		{
			ans *= a;
			ans %= m;
		}

	return ans;
}

int main()
{
	cin >> n >> m >> y;

	bool flag = false;
	for (int i = 0; i < m; i++)
		{
			if (pwr(i, n) == y)
				{
					cout << i << ' ';
					flag = true;
				}
		}
	
	if (!flag)
		cout << -1;

	return 0;
}
