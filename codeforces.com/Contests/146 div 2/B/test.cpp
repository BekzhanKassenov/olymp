#include <iostream>
#include <cmath>

using namespace std;

int d[1000010];

int mod = 1073741824;

void f(int i)
{
	int j;
	int h = 0;
	for (j = 2; j * j <= i; j++)
		{
			if (i % j == 0)
				h++;
		}

	j--;
	h *= 2;
	if (j * j == i)
		h -= 1;

	h += 2;
	d[i] = h;
}

int main()
{
	int i, j, n, m, k, a, b, c;

	cin >> a >> b >> c;

	int ans = 0, t;
	for (i = 1; i <= a; i++)
		for (j = 1; j <= b; j++)
			for (k = 1; k <= c; k++)
				{
					t = i * j * k;
					if (d[t] == 0)f(t);
					ans += d[t];
					if (ans > mod)
						ans -= mod;
				}
	cout << ans;	
}