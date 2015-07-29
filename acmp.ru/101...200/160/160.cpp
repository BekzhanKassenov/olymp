#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int a[110];

bool used[110] = {false};

int dfs(int n, int gl = 1)
{
	used[n] = true;

	if (used[a[n]])
		return gl;
	else
		return dfs(a[n], gl + 1);	
}

int gcd(int a, int b)
{
	if (a == 0 || b == 0)
		return a + b;

	if (a > b)
		return gcd(a % b, b);
		
	return gcd(b % a, a);	
}

int lcm(int a, int b)
{
	return ((a / gcd(a, b)) * b);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;

	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> a[i];

	int ans = 1;

	for (int i = 1; i <= n; i++)
		if (!used[i])
			ans = lcm(ans, dfs(i));

	cout << ans;

	return 0;
}
