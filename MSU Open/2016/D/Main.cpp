/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 1000 * 1000 * 10 + 100;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

bool prime[MAXN];
int pr[MAXN];
int A, B;

void sieve(int N) {
    memset(prime, true, sizeof prime);

    prime[0] = prime[1] = false;

    for (int i = 2; i <= N; i++) {
        if (prime[i]) {
            pr[i] = i;

            if (1ll * i * i > N) {
                break;
            }

            for (int j = i * i; j <= N; j += i) {
                prime[j] = false;
                pr[j] = i;
            }
        }
    }
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &A, &B);

    sieve(B);

    int ans = 0;
    for (int i = max(A, 2); i <= B; i++) {
        if (prime[i]) {
            continue;
        }

        int d = i / pr[i];
        if (d != pr[i] && prime[d]) {
            ans++;
        }
    }

    printf("%d\n", ans);
    
    return 0;
}
