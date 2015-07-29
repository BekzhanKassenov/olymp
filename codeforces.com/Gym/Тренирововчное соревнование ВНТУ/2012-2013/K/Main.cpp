/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);
const int maxn = 100010;

template <typename T>
inline T sqr(T n) {
	return (n * n);
}

ll fact[maxn], revfact[maxn];
char s[maxn], t[maxn];
int cnt_s[30], cnt_t[30];

ll C(int n, int k) {
	if (k > n)
		return 0;

	return (fact[n] * revfact[k] % MOD * revfact[n - k] % MOD);
}

ll pow_mod(ll n, int st) {
	if (st == 0)
		return 1ll;

	if (st & 1) {
		return (pow_mod(n, st - 1) * n % MOD);
	}

	ll b = pow_mod(n, st >> 1);

	return (b * b % MOD);
}

void build() {
	fact[0] = 1;

	for (int i = 1; i < maxn; i++)
		fact[i] = (fact[i - 1] * i) % MOD;

	for (int i = 0; i < maxn; i++)
		revfact[i] = pow_mod(fact[i], MOD - 2);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
    build();

    scanf("%s%s", s, t);

    for (int i = 0; s[i] != '\0'; i++) {
    	cnt_s[s[i] - 'a']++;
    }
	
	for (int i = 0; t[i] != '\0'; i++){
		cnt_t[t[i] - 'a']++;
	}

	ll res = 1;

	for (int i = 0; i < 26; i++) {
		res *= C(cnt_s[i], cnt_t[i]);
		res %= MOD;
	}

	printf("%I64d", res);

	return 0;
}
