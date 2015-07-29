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

int x, y, a, b, ans, ptr;
char buf[100010];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d%d%d", &x, &y, &a, &b);

    for (int vas = a; vas <= x; vas++) {
        for (int pet = b; pet <= y && pet < vas; pet++) {
            ans++;
            sprintf(buf + ptr, "%d %d\n", vas, pet);
            
            while (buf[ptr])
                ptr++;
        }
    }

    printf("%d\n%s", ans, buf);

    return 0;
}
