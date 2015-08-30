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
const int MAXN = 210;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, ca, cb, ans;
char s[MAXN];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    scanf("%d %d %d\n", &n, &ca, &cb);
    gets(s);

    if (ca + cb > n) {
        puts("-1");
        return 0;
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            if (ca) {
                ca--;
            } else {
                s[i] = 0;
            }
        } else if (s[i] == '1') {
            if (cb) {
                cb--;
            } else {
                s[i] = 0;
            }
        }
    }
    

    for (int i = 0; i < n; i++) {
        if (s[i] == 0) {
            if (ca) {
                ca--;
                s[i] = '0';
                ans++;
            } else if (cb) {
                cb--;
                s[i] = '1';
                ans++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == '2') {
            if (ca) {
                ca--;
                s[i] = '0';
                ans++;
            } else if (cb) {
                cb--;
                s[i] = '1';
                ans++;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (s[i] == 0) {
            s[i] = '2';
            ans++;
        }
    }

    printf("%d\n", ans);
    puts(s);

    return 0;
}