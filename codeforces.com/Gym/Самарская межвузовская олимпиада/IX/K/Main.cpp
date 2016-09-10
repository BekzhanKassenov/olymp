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

enum State {
    NOSKIP,
    SKIP_LEFT,
    SKIP_RIGHT
};

char s[MAXN];
int n;


int go(int l, int r, State state) {
    if (l == -1 && r == n) {
        if (state == NOSKIP) {
            return -1;
        }

        return INF;
    }

    if (s[l] == s[r]) {
        return go(l - 1, r + 1, state);
    }
    
    switch (state) {
        case SKIP_LEFT:
            if (go(l - 1, r, NOSKIP) == -1) {
                return l;
            } else {
                return INF;
            }
        case SKIP_RIGHT:
            if (go(l, r + 1, NOSKIP) == -1) {
                return r;
            } else {
                return INF;
            }
        default:
            return INF;
    }
}

void try_solve(int l, int r, State state) {
    int ret = go(l, r, state);
    if (ret != INF) {
        puts("YES");
        printf("%d\n", ret + 1); 
        exit(0);
    }
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    gets(s);
    n = strlen(s);

    if (n % 2 == 0) {
        int mid = n / 2;
        try_solve(mid - 1, mid + 1, SKIP_LEFT);
        mid--;
        try_solve(mid - 1, mid + 1, SKIP_RIGHT);
    } else {
        int mid = n / 2;
        try_solve(mid, mid + 1, SKIP_LEFT);
        try_solve(mid - 1, mid, SKIP_RIGHT);

        if (go(mid - 1, mid + 1, NOSKIP) == -1) {
            puts("YES");
            printf("%d\n", mid + 1);
        }
    }

    puts("NO");

    return 0;
}
