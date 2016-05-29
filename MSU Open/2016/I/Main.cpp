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
const int MAXN = 10010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
int power[MAXN];
int last;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    while (n % 2 == 0) {
        n /= 2;
    }

    while (n % 5 == 0) {
        n /= 5;
    }
    
    if (n == 1) {
        puts("YES");
        return 0;
    }

    power[last++] = 1;

    for (int p = 10 % n; p != 1; p = (p * 10) % n) {
        power[last++] = p;
    }

    for (int i = 0; i < last; i++) {
        for (int j = i; j < last; j++) {
            if ((power[i] + power[j]) % n == n - 1) {
                puts("YES");
                return 0;
            }
        }
    }

    puts("NO");
    return 0;
}
