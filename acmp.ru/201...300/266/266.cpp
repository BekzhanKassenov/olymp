#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int a[60 * 24];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
		{
			int x, y, x1, y1;

			cin >> x >> y >> x1 >> y1;

			if (x == x1 && y == y1)
				{
					for (int j = 0; j < 60 * 24; j++)
						a[j]++;
				}

			int m1 = x * 60 + y;
			int m2 = x1 * 60 + y1;

			for (int j = m1; j != m2; j = (j + 1) % (60 * 24))
				a[j]++;
		}

   	int ans = 0;

   	for (int i = 0; i < 60 * 24; i++)
   		if (a[i] == n)
   			ans++;

   	cout << ans;

   	return 0;
}
