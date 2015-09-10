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
const int MAXN = 1000010;
const int TRIALS = 20;
const int LEN = 5;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
int x[MAXN], y[MAXN];

int get_rand(int num) {
    return ((rand() << 16) ^ rand()) % num;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "w", stdout);
#endif

    n = 1000000;
    
    printf("%d\n", n);

    for (int i = 0; i < n; i++) {
        printf("%d %d\n", get_rand(1000000), get_rand(1000000));
    }

    puts("");
    
    return 0;
}
