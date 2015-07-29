#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define ll long long

ll str_to_int(string s)
{
	ll ans = 0;

	for (int i = 0; i < (int)s.length(); i++)
		{
			ans *= 10;
			ans += s[i] - '0';
		}

	return ans;	
}

bool prime(ll n)
{
	for (ll i = 2; i * i <= n; i++)
		if (n % i == 0)
			return false;

 	return (n == 1 || n == 0 ? false : true);
}

void print(ll n)
{
	string s;

	while (n)
		{
			s += n % 10 + '0';
			n /= 10;
		}

	reverse(s.begin(), s.end());

	int k = s.length();

	for (int i = k; i < 12; i++)
		s = '0' + s;

	cout << s;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	cin >> n;

	string s;

	cin >> s;

	for (int i = 0; i < 12 - n; i++)
		s += '0';

	long long tmp = str_to_int(s);

	for (;;)
		{
			if (prime(tmp))
				{
					print(tmp);
					return 0;
				}

			tmp++;
		}
}
