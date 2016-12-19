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
const int MAXN = 300;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
char s[MAXN];
int cnt[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d\n", &n);
    gets(s);

    if (n % 4 != 0) {
        puts("===");
        return 0;
    }

    vector <char> keys{'A', 'C', 'G', 'T'};

    for (int i = 0; i < n; i++) {
        if (s[i] != '?') {
            cnt[s[i]]++;
        }
    }

    for (char c : keys) {
        if (cnt[c] > n / 4) {
            puts("===");
            return 0;
        }
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == '?') {
            for (char c : keys) {
                if (cnt[c] != n / 4) {
                    s[i] = c;
                    cnt[c]++;
                    break;
                }
            }
        }
    }

    puts(s);

    return 0;
}
