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
        return (n * pow_mod(n, st - 1, MOD)) % MOD;
    else
        {
            ll b = pow_mod(n, st >> 1, MOD);

            return (b * b) % MOD;
        }    
}

int len;

void move(ll& hash, ll f, ll s, ll base, ll MOD)
{
    hash = (hash - ((f * pow_mod(base, len - 1, MOD)) % MOD) + MOD) % MOD;

    hash = (hash * base) % MOD;

    hash = (hash + s) % MOD;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s, t;

    cin >> s >> t;

    if (s.size() < t.size())
        {
            return 0;
        }

    len = t.size();

    int len1 = s.size();

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
        printf("0 ");

    for (int i = 0; i < len1 - len; i++)
        {
            move(hash_s1, s[i], s[i + len], base1, MOD1);
            move(hash_s2, s[i], s[i + len], base2, MOD2);
            
            if (hash_s1 == hash_t1 && hash_s2 == hash_t2)
                printf("%d ", i + 1);
        }   

    return 0;    
}
