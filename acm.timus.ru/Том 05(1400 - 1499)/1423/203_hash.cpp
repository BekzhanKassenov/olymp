#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

typedef long long ll;

const ll base1 = 37;
const ll base2 = 39;

const ll MOD1 = (1000 * 1000 * 1000 + 7);
const ll MOD2 = (1000 * 1000 * 1000 + 9);

ll pow_mod(ll n, ll st, ll MOD)
{
	if (st == 0)
		return 1;

   	if (st & 1)
   		{
   			return (n * pow_mod(n, st - 1, MOD)) % MOD;
   		}
   	else
   		{
   			ll b = pow_mod(n, st >> 1, MOD);

   			return ((b * b) % MOD);
   		}	
}

int len;

void move(ll& hash, ll c, ll base, ll MOD)
{
	hash = (hash - c + MOD) % MOD;

	hash = (hash * pow_mod(base, MOD - 2, MOD)) % MOD;

	hash = (hash + c * pow_mod(base, len - 1, MOD)) % MOD;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int len;

	cin >> len;

	string s, t;
	
	cin >> s >> t;

	ll hash_s1 = 0, hash_s2 = 0;
	ll hash_t1 = 0, hash_t2 = 0;

	for (int i = 0; i < len; i++)
		{
			hash_s1 = (hash_s1 * base1 + s[i]) % MOD1;
			hash_s2 = (hash_s2 * base2 + s[i]) % MOD2;

			hash_t1 = (hash_t1 * base1 + t[i]) % MOD1;
			hash_t2 = (hash_t2 * base2 + t[i]) % MOD2;
		}

	if (hash_s1 == hash_t1 && hash_s2 == hash_t2)
		{
			cout << 0;

			return 0;
		}

	for (int i = len - 1; i >= 0; i--)
		{
			move(hash_s1, (ll)s[i], base1, MOD1);
			move(hash_s2, (ll)s[i], base2, MOD2);

			if (hash_s1 == hash_t1 && hash_s2 == hash_t2)
				{
					cout << len - i;

					return 0;
				}
		}

   	cout << -1;

   	return 0;
}
