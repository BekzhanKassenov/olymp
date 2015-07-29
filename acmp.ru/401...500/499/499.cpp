#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int k, w;

	cin >> k >> w;

	int a[3], b[3];

	for (int i = 0; i < 3; i++)
		cin >> a[i] >> b[i];

	for (int mask = 0; mask < 8; mask++)
		{
			int a1 = 0, a2 = 0;
			for (int i = 0; i < 3; i++)
				{
					if (mask & (1 << i))
						{
							a1 += a[i];
							a2 += b[i];
						}
				}

			if (a1 <= w && a2 >= k)
				{
					cout << "YES";
					return 0;
				}
		}

	cout << "NO";
	return 0;
}
