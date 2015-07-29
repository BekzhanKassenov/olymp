#include <iostream>
#include <cstdio>

using namespace std;

long long fact(int n)
{
	long long ans;

	if (n == 0 || n == 1)
		return 1;

	else
		{
			ans = fact(n - 1) * n;
			return ans;
		}
}

long long c(int m, int n)
{
	long long ans;

	ans = fact(n);

	ans /= fact(m);

	ans /= fact(n - m);

	return ans;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m;

	cin >> n >> m;

	long long ans = 0;

	for (int i = m; i <= n; i++)
		{
			ans += c(i, n);
		}	

	cout << ans;

	return 0;
}

