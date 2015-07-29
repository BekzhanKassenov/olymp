#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define MOD (1000 * 1000 * 1000)

int gcd(int a, int b)
{
	if (a == 0 || b == 0)
		return a + b;

	if (a > b)
		return gcd(a % b, b);
	else
		return gcd(a, b % a);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int i, j;

	cin >> i >> j;

	int n = gcd(i, j);

	int f0 = 0, f1 = 1;

	if (n == 1 || n == 0)
		{
			cout << n;

			return 0;
		}

	int f2 = 0;

	for (int i = 2; i <= n; i++)
		{
			f2 = (f0 + f1) % MOD;
			f0 = f1;
			f1 = f2; 
		}

	cout << f2;

	return 0;
}
