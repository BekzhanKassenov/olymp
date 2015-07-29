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

int a1, b1;
int a2, b2;
int a3, b3;

bool test(int a1, int b1, int a2, int b2) {
    return (a1 >= a2 && b1 >= b2) ||
           (a1 >= b2 && b1 >= a2);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &a1, &b1);
    scanf("%d%d", &a2, &b2);
    scanf("%d%d", &a3, &b3);

    if (b1 >= b2 && test(a1 - a2, b1, a3, b3)) {
        puts("YES");
        return 0;
    }
    
    if (a1 >= a2 && test(a1, b1 - b2, a3, b3)) {
        puts("YES");
        return 0;
    }
    
    if (b1 >= a2 && test(a1 - b2, b1, a3, b3)) {
        puts("YES");
        return 0;
    }
    
    if (a1 >= b2 && test(a1, b1 - a2, a3, b3)) {
        puts("YES");
        return 0;
    }
    
    puts("NO");

    return 0;
}
