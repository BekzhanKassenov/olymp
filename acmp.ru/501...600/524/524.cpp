#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int m, n, x, y;

	cin >> m >> n >> x >> y;

	if (m == x && n == y)
		{
			cout << 0;
			return 0;
		}

	if (abs(m - x) == abs(n - y))
		{
			cout << 1;

			return 0;
		}

	if ((m + n) % 2 != (x + y) % 2)
		{
			cout << 0;

			return 0;

		}

	cout << 2 << endl;

	for (int i = 1; i <= 8; i++)
		for (int j = 1; j <= 8; j++)
			{
				if (abs(i - m) == abs(j - n) && abs(i - x) == abs(j - y))
					{
						cout << i << ' ' << j << endl;
						return 0;
					}
			}
}
