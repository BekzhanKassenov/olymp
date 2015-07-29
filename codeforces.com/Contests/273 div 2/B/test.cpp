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

int n, m;
int ansmin = INF;
int ansmax = 0;

int get_pairs(int n) {
    return n * (n - 1) / 2; 
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d %d\n", &n, &m);
    
    for (int i = 1; i < n; i++) {
        int a = i, b = n - i;

        ansmin = min(ansmin, get_pairs(a) + get_pairs(b));
        ansmax = max(ansmax, get_pairs(a) + get_pairs(b));
    }

    printf("%d %d\n", ansmin, ansmax);

    return 0;
}
