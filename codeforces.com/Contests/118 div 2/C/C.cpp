#include <iostream>
#include <cstdio>

#define MOD 1000000007

using namespace std;

long long pw(long long n, long long st)
{
	if (st == 0)
		return 1;
	if (st % 2 == 1)
		return (pw(n, st - 1) * n) % MOD;
	else
		{
			long long a = pw(n, st / 2) % MOD;
			return (a * a) % MOD;
		}
}

int main()
{
	long long n;
	cin >> n;
	if (n == 0)
		{cout << 1; return 0;}
	cout << (pw(2, 2 * n - 1) + pw(2, n - 1)) % MOD;
}

