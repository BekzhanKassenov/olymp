#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int k, p;

	cin >> k >> p;

	for (int x = 0; x < p; x++)
		{
			for (int y = 0; y < p; y++)
				{
					long long tmp = x * 1ll * x + y * 1ll * y;

					tmp %= p;

					if (tmp == k)
						{
							cout << x << ' ' << y;
							return 0;
						}
				}
		}
}
