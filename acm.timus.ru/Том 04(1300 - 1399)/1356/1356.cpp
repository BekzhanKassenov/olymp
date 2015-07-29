#include <iostream>
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

const int count_of_primes = 10000000;

vector <bool> prime;

void build()
{
	prime.resize(count_of_primes + 1, true);

	prime[0] = prime[1] = false;

	for (int i = 2; i <= count_of_primes; i++)
		{
			if (prime[i])
				{
					if (i * 1ll * i <= count_of_primes)
						for (int j = i * i; j <= count_of_primes; j += i)
							prime[j] = false;
				}
		}
}

map <int, bool> m;

bool is_prime(int n)
{
	if (n == 1)
		return false;

	if (n <= count_of_primes)
		return prime[n];

	if (m.find(n) != m.end())
		return m[n];

	bool flag = true;

	for (int i = 2; i * i <= n; i++)
		{
			if (n % i == 0)	
				flag = false;
		}

	m[n] = flag;

	return flag;

}

void solve(int n)
{	
	if (is_prime(n))
		{
			cout << n << endl;
			return;
		}

	if (n == 0)
		return;

	if (is_prime(n - 2))
		{
			cout << 2 << ' ' << n - 2 << endl;
			return;
		}

	if (n % 2 == 0)
		{
			for (int i = 2; i <= n / 2; i++)
				{
					if (is_prime(i) && is_prime(n - i))
						{
							cout << i << ' ' << n - i << endl;
							return;
						}
				}
		}
	else
		{
			cout << 3 << ' ';

			solve(n - 3);
		}	
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
  	#endif

  	int n;

  	cin >> n;

  	build();

  	for (int i = 0; i < n; i++)	
  		{
  			int a;

  			cin >> a;

  			solve(a);
  		}

  	return 0;
}
