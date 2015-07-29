#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

vector <int> a;

int main()
{
	int n;
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int tmp = n / 2;

	set <int> set1;

	for (int mask = 0; mask < (1 << tmp); mask++)
		{
			int x = 0;
			int i = mask;
			while (i)
				{
					if (i & 1)
						x += a[i];
					else
						x -= a[i];

					i >>= 1;
				}
			set1.insert(x);
		}
}
