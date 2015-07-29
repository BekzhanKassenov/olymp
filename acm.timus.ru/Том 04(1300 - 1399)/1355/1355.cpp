#include <iostream>
#include <cstdio>

using namespace std;

int cnt(int n)
{
	if (n == 1)
		return 0;

	if (n >= 2 && n <= 3)
		return 1;

	int ans = 0;

	int c = n;

	for (int i = 2; i * i <= n; i++)
		{
			while (c % i == 0)	
				{
					c /= i;
					ans++;
				}

			if (c == 1)
				break;
		}

	if (c > 1)
		ans++;

	return ans;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
		{
			int a, b;

			cin >> a >> b;

			if (a > b)
				{
					cout << 0 << endl;
					continue;
				}

			if (b % a == 0)
				cout << cnt(b / a) + 1 << endl;
			else
				cout << 0 << endl;
		}

	return 0;
}
