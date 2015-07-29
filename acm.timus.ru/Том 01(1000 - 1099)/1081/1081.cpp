#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	cin >> n;

	int k;

	cin >> k;

	vector <long long> f(n + 1);

	f[0] = 1;
	f[1] = 2;

	for (int i = 2; i <= n; i++)
		f[i] = f[i - 1] + f[i - 2];

	if (k > f[n])
		{
			cout << -1;
			return 0;
		}

	vector <bool> used(n + 1);

	for (int i = n - 1; i >= 0; i--)
		{
			if (k > f[i])
				{
					used[i] = true;
					k -= f[i];
				}
		}

	for (int i = n - 1; i >= 0; i--)
		if (used[i])
			cout << '1';
		else
			cout << '0';

	return 0;
}
