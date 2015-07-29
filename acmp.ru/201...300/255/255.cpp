#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;

	cin >> n;

	int ans = 0;

	for (int i = 2; i * i <= n; i++)
		{
			if ((n - i) % i == 0 && n % i == 0)
				ans = max(ans, i);

			if ((n - n / i) % (n / i) == 0 && n % i == 0)
				ans = max(ans, n / i);
		}

	if (ans == 0)
		{
			cout << 1 << ' ' << n - 1;
			return 0;
		}

	cout << ans << ' ' << n - ans;

	return 0;	
}
