#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int x, y;

	cin >> x >> y;

	int f1 = 0, f2 = 1, f3;

	f3 = f1 + f2;

	for (int i = 3; i <= x; i++)
		{
			f1 = f2;
			f2 = f3;
			f3 = f1 + f2;
		}

	for (int ans = 0; ans < y; ans++)
		{
			int t = y - f2 * ans;
			if (t % f1 == 0)
				{
					t /= f1;

					if (t > ans && ans > 0)
						{
							cout << t << ' ' << ans;
							return 0;
						}
				}
		}
}
