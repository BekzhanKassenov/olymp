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

int cnt[10], x;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    for (int i = 0; i < 6; i++) {
        scanf("%d", &x);
        cnt[x]++;
    }

    for (int i = 0; i < 10; i++) {
        if (cnt[i] >= 4) {
            cnt[i] -= 4;
            for (int j = 0; j < 10; j++) {
                if (cnt[j] == 2) {
                    puts("Elephant");
                    return 0;
                }
            }

            puts("Bear");
            return 0;
        }
    }

    puts("Alien");
    
    return 0;
}
