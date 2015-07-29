#include <iostream>
#include <cstdio>
#include <map>
#include <vector>

using namespace std;

int f(long long n)
{
	if (n == 0 || n == 1)
		return n;

	if ((n & 3) == 0)
		return f(n >> 2);

	if ((n & 3) == 1)
		return ((f(n >> 2) << 1) + f((n >> 2) + 1));

	if ((n & 3) == 2)
		return (f(n >> 2) + f((n >> 2) + 1));

	if ((n & 3) == 3)
		return (f(n >> 2) + (f((n >> 2) + 1) << 1));

}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif            

	long long n;

	while (cin >> n && n != 0)
		{
			int k = 0;

			while ((1ll << k) - 1 <= n)
				k++;

			cout << f((1ll << k) - 1) << endl;
		}

	return 0;
}