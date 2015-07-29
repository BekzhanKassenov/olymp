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

int n, cnt = 1;

void print(int empty, int full) {
    for (int i = 0; i < empty; i++)
        putchar('*');

    for (int i = 0; i < full; i++)
        putchar('D');

    for (int i = 0; i < empty; i++)
        putchar('*');

    puts("");
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n / 2; i++) {
        int temp = (n - cnt) / 2;
        print(temp, cnt);
        cnt += 2;
    }

    for (int i = n / 2; i < n; i++) {
        int temp = (n - cnt) / 2;
        print(temp, cnt);
        cnt -= 2;
    }
    
    return 0;
}
