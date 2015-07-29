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

const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);
const int maxn = 100010;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

int n, x, a[maxn], pos[maxn];

bool prime[maxn];
int primes[maxn], sz;
vector <pair <int, int> > ans;

void build() {
    memset(prime, true, sizeof prime);
    prime[0] = false;
    prime[1] = false;

    for (int i = 2; i < maxn; i++) {
        if (prime[i]) {
            primes[sz++] = i;

            if (i * 1ll * i < maxn)
                for (int j = i * i; j < maxn; j += i)
                    prime[j] = false;
        }
    }
}

void move_to(int r, int l) {
    if (r == l)
        return;

    if (prime[r - l + 1]) {
        ans.push_back(MP(l, r));
        pos[a[l]] = r;
        pos[a[r]] = l;
        swap(a[l], a[r]);
        return;
    }

    int val = *(lower_bound(primes, primes + sz, r - l + 1) - 1);

    pos[a[r - val + 1]] = r;
    pos[a[r]] = r - val + 1;
    swap(a[r - val + 1], a[r]);
    ans.push_back(MP(r - val + 1, r));

    move_to(r - val + 1, l);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    
    scanf("%d", &n);

    build();

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        pos[a[i]] = i;
    }

    for (int i = 1; i <= n; i++) {
        int p = pos[i];

        move_to(p, i);
    }
    
    printf("%u\n", ans.size());

    for (size_t i = 0; i < ans.size(); i++)
        printf("%d %d\n", ans[i].F, ans[i].S);

    return 0;
}
