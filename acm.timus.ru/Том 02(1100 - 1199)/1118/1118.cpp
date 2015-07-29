#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

double triv(int n)
{
	double tmp = 1;

	if (n == 1)
		return 0;

	for (int i = 2; i * i <= n; i++)
		{
			if (n % i == 0)
				{
					tmp += i;
					if (i * i != n)
						tmp += n / i;
				}
		}
	return (tmp / (double(n)));
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int i, j;

	cin >> i >> j;

	if (i == 1 || j == 1)
		{
			cout << 1;
			return 0;
		}

	double ans = 2e9;

	int q = 0;

	vector <int> prime(j + 1, true);

	prime[0] = prime[1] = 0;

	for (int k = 2; k <= j; k++)	
		{
			if (prime[k])
				{
					if (k * 1ll * k <= j)
						{
							for (int w = k * k; w <= j; w += k)
								prime[w] = false;
						}
				}
		}


	int t = -1;

	for (int k = i; k <= j; k++)
		if (prime[k])
			t = max(t, k);

	if (t != -1)
		{
			cout << t;
			return 0;
		}

	for (int k = i; k <= j; k++)
		{
			double z = triv(k);

			if (z < ans)
				{
					ans = z;
					q = k;
				}
		}

	cout << q << endl;	
}

