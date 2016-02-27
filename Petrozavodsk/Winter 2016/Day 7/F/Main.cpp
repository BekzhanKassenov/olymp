/****************************************
**          Solution by NU #2          **
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

int n, d;
int a[MAXN];
int dp[1 << 16];

int read() {
    char buf[20];
    gets(buf);

    int mask = 0;
    for (int i = 0; i < d; i++) {
        mask <<= 1;
        mask |= buf[i] - '0';
    }

    return mask;
}

int f(int mask) {
    return mask & (mask - 1);
}

void add(int& a, int addend) {
    a += addend;
    if (a >= MOD) {
        a -= MOD;
    }
}

void subtr(int& a, int addend) {
    a -= addend;
    if (a < 0) {
        a += MOD;
    }
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d%d\n", &n, &d);

    for (int i = 0; i < n; i++) {
        a[i] = read();                   
    }

    int totalSum = 0;
    for (int i = 0; i < n; i++) {
        int bitcount = __builtin_popcount(a[i]);

        if (bitcount != d) {
            int res = 0;
            for (int sub = a[i]; sub >= 0; sub = (sub - 1)&a[i]) {
                add(res, dp[sub]);
                //add(totalSum, dp[sub]);
                                   
                if (sub == 0) {
                    break;
                }
            }
            
            //subtr(totalSum, dp[a[i]]);
            add(dp[a[i]], res);
            add(totalSum, res);
        } else {
            add(dp[a[i]], totalSum);
            add(totalSum, totalSum);
        }
        //cout << totalSum << ' ' << endl;
        add(dp[a[i]], 1);
        add(totalSum, 1);
        //add(result, dp[a[i]]);
    }

    printf("%d\n", totalSum); 

    return 0;
}
/*
5 6
101011
100011
001111
110011
110001
*/




