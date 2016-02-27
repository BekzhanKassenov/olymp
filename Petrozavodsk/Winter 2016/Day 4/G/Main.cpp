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

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int k;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &k);

    printf("%d\n", 2 * k);

    int s1 = 2, s2 = k + 2;

    for (int i = 1; i <= k; i++) {
        printf("%d %d\n", i, i + k);
        for (int j = 0; j < k - 1; j++) {
            int node = s1 + j;
            if (node > 2 * k) {
                node -= 2 * k;
            }

            printf("%d %d\n", node, i);
        }

        for (int j = 0; j < k - 1; j++) {
            int node = s2 + j;
            if (node > 2 * k) {
                node -= 2 * k;
            }

            printf("%d %d\n", node, i + k);
        }

        s1++, s2++;
    }
    
    return 0;
}
