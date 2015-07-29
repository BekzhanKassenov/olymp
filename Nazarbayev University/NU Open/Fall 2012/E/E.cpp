#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>

using namespace std;

vector <int> prime;

vector <int> primes;

int build(int n)
{
	int ans = 0;
	prime.assign(n + 1, true);

	prime[0] = prime[1] = false;

	for (int i = 2; i <= n; i++)
		{
			ans += prime[i];
			if (prime[i])
				{
					primes.push_back(i);
					if (i * 1ll * i <= n)
						for (int j = i * i; j <= n; j += i)
							prime[j] = false;
				}
		} 

	return ans;
}

bool isPrime(int n)
{
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0)
			return false;

	return true;
}


int main()
{
	freopen("primes.in", "r", stdin);
	freopen("primes.out", "w", stdout);

	int n;

	cin >> n;

	if (n == 1)
		{
			cout << 2 << endl;
			return 0;
		}

	int tmp = 0;

	int q = 0;

	int cnt = build(1000000);

	if (isPrime(n))
		{
			cout << n;
			return 0;
		}

	set <int> ans;

	for (int i = 0; i < cnt; i++)
		{
			q++;
			tmp += primes[i];
			ans.insert(primes[i]);
			if (tmp >= n && tmp % n == 0)
				{
					break;
			   }

			if (n - tmp > 0 && prime[n - tmp] && ans.find(n - tmp) == ans.end())
				{
					ans.insert(n - tmp);
					break;
				}

		}

	for (set <int, int> :: iterator it = ans.begin(); it != ans.end(); it++)	
		cout << *it << ' ';
	return 0;
}
