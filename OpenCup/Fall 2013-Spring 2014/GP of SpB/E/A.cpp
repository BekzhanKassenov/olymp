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
#define y0 y0_lal
#define y1 y1_lal
#define yn en_lal
#define j0 j0_lal
#define j1 j1_lal
#define jn jn_lal
#define next next_lal
#define prev prev_lal
#define File "fourprimes"

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

const int maxn = 100010;

int cnt[maxn];
bool prime[maxn];
vector <int> a;
int sz;

void build() {
    memset(prime, 1, sizeof prime);
    prime[0] = prime[1] = false;

    for (int i = 2; i < maxn; i++) {
        if (prime[i]) {
            a.push_back(i);

            if (i * 1ll * i < maxn)
                for (int j = i * i; j < maxn; j += i)
                    prime[j] = false;
        }
    }
    sz = a.size();
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);

    int n;
    cin >> n;

    build();

    for (int i = 0; i < sz; i++)
        for (int j = 0; j < sz; j++)
            if (a[i] + a[j] <= n)
                cnt[a[i] + a[j]]++;

    ll res = 0;

    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            if (n - a[i] - a[j] >= 0)
                res += 1ll * cnt[n - a[i] - a[j]];
        }
    }

    cout << res;

    return 0;
}
