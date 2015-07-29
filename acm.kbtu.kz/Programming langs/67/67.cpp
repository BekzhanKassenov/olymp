#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
	int r1, k1, r2, k2;
	cin >> r1 >> k1 >> r2 >> k2;

	int c1 = 0;

	for (int i = r1; ;i++)
		{
			c1 ++;
			if (i == 7)
				i = 1;

			if (i == r2)
				break;
		}
	int c2 = 0;
	for (int i = r1; ; i--)
		{
			c2 ++;
			if (i == 7)
				i = 1;
		}
	cout << min(c1,c2) * min(k1, k2) + max(k1, k2) - min(k1, k2);
	return 0;
}
