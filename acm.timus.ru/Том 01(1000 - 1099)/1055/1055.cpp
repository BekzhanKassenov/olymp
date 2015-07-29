#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

const int sz = 50010;

vector <bool> prime(sz, true);

void build()
{
	prime[0] = prime[1] = false;

	for (int i = 2; i < sz; i++)
		{
			if (prime[i] && i * 1ll * i < sz)
				{
					for (int j = i * i; j < sz; j += i)
						prime[j] = false;
				}
		}
}

void get_next_prime(int& k)
{
	for (int i = k + 1; i < sz; i++)
		if (prime[i])
			{
				k = i;
				return;
			}
}

vector <int> cnt(sz, 0);

void fact(int n, int d)
{
	vector <int> ans;

	int k = (int)sqrt((double(n)));

	if (prime[n])
		{
			cnt[n] += d;
			return;
		}

	for (int i = 2; i <= k + 2; i++)
		{
			if (n % i == 0 && prime[i] && n > 1)
				{
					while (n % i == 0 && n > 1)
						{
							cnt[i] += d;
							n /= i;
						}
				}
		}
	if (prime[n])
		cnt[n] += d;
}

int main()
{
	int n, m;

	cin >> n >> m;

	if (m > n) 
		{
			cout << 0;
			return 0;
		}

	if (n == m)
		{
			cout << 1;
			return 0;
		}

	build();

	for (int i = m + 1; i <= n; i++)
		{
			fact(i, 1);
		}


	for (int i = 2; i <= n - m; i++)
		{
			fact(i, -1);
		}

	int ans = 0;

	for (int i = 0; i < sz; i++) {
		ans += (cnt[i] != 0);
		if (cnt[i] > 0)
			cout << i << " ^ " << cnt[i] << endl;
	}

	cout << ans;
	return 0;
}
