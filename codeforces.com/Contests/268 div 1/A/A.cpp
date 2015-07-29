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

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    if (n < 4) {
        puts("NO");
        return 0;
    }

    puts("YES");

    if (n & 1) {
        for (int i = n; i > 5; i -= 2)        
            printf("%d - %d = 1\n", i, i - 1);
                                              
        for (int i = n; i > 5; i -= 2)        
            puts("1 * 1 = 1");                

        puts("5 * 3 = 15");
        puts("2 * 4 = 8");
        puts("8 + 1 = 9");
        puts("15 + 9 = 24");
    } else {
        
        for (int i = n; i > 4; i -= 2)        
            printf("%d - %d = 1\n", i, i - 1);
                                              
        for (int i = n; i > 4; i -= 2)        
            puts("1 * 1 = 1");                
        
        int cur = 1;
        for (int i = 2; i <= 4; i++) {
            printf("%d * %d = %d\n", cur, i, cur * i);
            cur *= i;
        }
    }

    return 0;
}
