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
const int MAXN = 200010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int m, x;
char s[MAXN];
bool used[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    gets(s + 1);
    scanf("%d\n", &m);

    while (m--) {
        scanf("%d", &x);
        used[x] ^= true;
    }

    int l = 1, r = strlen(s + 1);

    bool flag = false;
    while (l < r) {
        flag ^= used[l];

        if (flag) {
            swap(s[l], s[r]);
        }

        l++, r--;
    }

    puts(s + 1);
    
    return 0;
}
