#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

#define ll long long

const long long MAX = 100000ll * 100000ll * 100000ll + 1;

long long ans = 0;

long long pow(ll n, ll k)
{
	long long res = 1;

	while (k)
		{
			if (k & 1)
				res *= n;

			if (res > MAX || res < 0)
				{
					return -1;
				}

			n *= n;

			k >>= 1;
		}

	return res;
}

int pr[1000];

bool prime(int n)
{
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0)
			return false;

	return (n != 1 ? true : false);
}

void build()
{
	int uk = 0;

	int nmb = 2;

	while (uk < 1000)
		{
			if (prime(nmb))
				pr[uk++] = nmb;

			nmb++;
		}
}

void rec(int n, int s[5001])
{
	if (n == 1)
		{
			int uk = 0;
			long long tmp = 1;

			for (int i = 5000; i >= 0; i--)	
				{
					for (int j = 0; j < s[i]; j++)
						{
							long long q = pow(pr[uk], i - 1);
							
			//				cout << pr[uk] << " ^ "  << i - 1 << " = " << q << endl;
							
							tmp *= q;
							
							uk++;
							
							if (tmp > MAX || q < 0 || tmp < 0)
								return;
						}
				}

			//cout << tmp << endl;	


			if (ans == 0)
				ans = tmp;
			else
				if (tmp != 0)	
					ans = min(ans, tmp);

			return;
		}

	for (int i = 2; i * i <= n; i++)
		{
			if (n % i == 0)
				{
					s[i]++;
					rec(n / i, s);
					s[i]--;
				}
		}

	s[n]++;
	rec(1, s);
	s[n]--;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;

	cin >> n;

	build();

	int s[5001] = {0};

	rec(n, s);

	cout << ans;

	return 0;
}
