#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

#define LIM 10000

int main()
{
	int x, y, z;
	cin >> x >> y >> z;
	int n = 0, m = 0 ,k = 0;
	for (int i = 1; i <= 100; i++)
	{
		if (x % i == 0)
			{
				k = x / i;
				m = i;
			}
		else
			continue;
	for (int c = 1; c <= 10000; c++)
		{
			if (y == m * c && z == k * c)
				{
					cout << (4 * (k + m + c)) << endl;
					return 0;
				}
		}
	}
	return 0;
}
