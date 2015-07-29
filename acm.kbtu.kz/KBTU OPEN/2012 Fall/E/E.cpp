#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define ll long long
#define MOD (1000 * 1000 * 1000 * 1ll + 7)

struct cmp {
    ll x, y;
};

cmp operator * (const cmp& a, const cmp& b) {
    cmp ans;

    ans.x = ((a.x * b.x) % MOD - (a.y * b.y) % MOD + MOD) % MOD;

    while (ans.x < 0)
        ans.x += MOD;

    ans.y = ((a.x * b.y) % MOD + (a.y * b.x) % MOD + MOD) % MOD;

    while (ans.y < 0)
        ans.y += MOD;

    return ans;
}

cmp power(const cmp a, ll n) {
    if (n == 1)
        return a;

    cmp ans;

    if (n == 0)
        {
            ans.x = 1;
            ans.y = 1;
            return ans;
        }

    if (n & 1)
        {
            return a * power(a, n - 1);
        }
    else
        {
            ans = power(a, n >> 1);

            cmp b = ans;

            return (ans * b);
        }
}

int main()
{
    freopen("gaussian.in", "r", stdin);
    freopen("gaussian.out", "w", stdout);

    cmp a;

    ll n;

    cin >> a.x >> a.y >> n;

    a = power(a, n);

    while (a.x < 0)
        a.x += MOD;

    while (a.y < 0)
        a.y += MOD;

    cout << a.x << ' ' << a.y;

    return 0;
}
