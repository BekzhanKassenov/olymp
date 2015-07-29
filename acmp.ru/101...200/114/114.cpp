#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int check(int mask, int n)
{
	if (!(mask & (1 << (n - 1))))
		return (-1);

	for (int i = 1; i < n; i++)
		{
			if (!(mask & (1 << i)) && !(mask & (1 << (i - 1))))
				return (-1);
		}

	int ans = 0;

	while (mask)
		{
			ans += (mask & 1);
			mask >>= 1;
		}
	return ans;

}


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);	

	int n, k;

	cin >> n >> k;

	int ans = 0;

	for (int mask = 0; mask < (1 << n); mask++)
		{
			int c = check(mask, n);

			if (c == -1)
				continue;

			int pl = 1;

			for (int i = 0; i < c; i++)
				pl *= (k - 1);

			ans += pl;
		}

	cout << ans;
}
