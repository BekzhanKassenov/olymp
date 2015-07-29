#include <iostream>
#include <cstdio>

using namespace std;

int solve(int n)
{
	int ans = 0;

	while (n != 2)
		{
			if (n & 1)
				{
					n = 3 * n + 1;
				}
			else
				n >>= 1;
			ans++;	
		}

	return ans;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m;

	cin >> n >> m;

	int ans = 0;

	for (int i = n; i <= m; i++)
		ans += solve(i);

	cout << ans;

	return 0;	
}
