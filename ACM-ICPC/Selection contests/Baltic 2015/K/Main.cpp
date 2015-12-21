/****************************************
**     Solution by Bekzhan Kassenov    **
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

int n;
long long fact[22], x;
set <long long> Set;

bool check(long long a, long long b) {
    long double aa = a;
    long double bb = b;
    return aa * bb <= 1e18;
}

void gen(long long val, int pos) {
    Set.insert(val);

    if (pos == 21) {
        return;
    }

    gen(val, pos + 1);
    for (int i = 0; check(val, fact[pos]); i++) {
        val *= fact[pos];
        gen(val, pos + 1);
    }
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    fact[0] = 1;
    for (int i = 1; i <= 20; i++) {
        fact[i] = i * fact[i - 1];
    }
    
    gen(1, 2);

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%I64d\n", &x);

        if (Set.count(x)) {
            puts("YES");
        } else {
            puts("NO");
        }
    }


    return 0;
}
