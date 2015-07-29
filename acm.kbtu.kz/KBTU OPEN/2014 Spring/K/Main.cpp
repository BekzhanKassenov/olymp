/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "zero"

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
const int maxn = 2010;
const int maxsum = 5 * 20010;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

ll mem1[maxsum], mem2[maxsum], *dp_l, *dp_r, res;
int n, a[maxn];

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }

    dp_l = mem1 + maxsum / 2;
    dp_r = mem2 + maxsum / 2;

    memset(mem1, 0, sizeof mem1);
    memset(mem2, 0, sizeof mem2);

    for (int i = 2; i < n; i++) {
        for (int j = i + 1; j < n; j++)
            dp_r[a[i] + a[j]]++;
    }

    dp_l[a[0] + a[1]]++;

    for (int i = 2; i < n - 2; i++) {
        for (int j = i + 1; j < n; j++)
            dp_r[a[i] + a[j]]--;

        for (int j = -maxsum / 2 + maxn + 100; j < maxsum / 2 - 100 - maxn; j++)
            res += dp_l[j] * dp_r[-(j + a[i])];

        for (int j = 0; j < i; j++)
            dp_l[a[i] + a[j]]++;
    }

    printf("%I64d", res);

    return 0;
}
                