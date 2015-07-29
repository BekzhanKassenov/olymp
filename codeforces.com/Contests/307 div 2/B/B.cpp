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
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

char a[MAXN], b[MAXN], c[MAXN];
int cnta[26], cntb[26], cntc[26];
int ansb, ansc;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    gets(a);
    gets(b);
    gets(c);

    for (int i = 0; a[i]; i++) {
        cnta[a[i] - 'a']++;
    }

    for (int i = 0; b[i]; i++) {
        cntb[b[i] - 'a']++;
    }

    for (int i = 0; c[i]; i++) {
        cntc[c[i] - 'a']++;
    }

    for (long long num = 0; num < MAXN; num++) {
        bool ok = true;

        for (int i = 0; i < 26; i++) {
            if (cntb[i] * num > cnta[i]) {
                ok = false;
            }
        }

        int tempb = num;
        if (!ok) {
            tempb = 0;
        }

        int tempc = 2 * MAXN;

        for (int i = 0; i < 26; i++) {
            if (cntc[i] != 0) {
                tempc = min(tempc, (int)(cnta[i] - tempb * cntb[i]) / cntc[i]);
            }
        }

        if (tempc != 2 * MAXN && tempb + tempc > ansb + ansc) {
            ansb = tempb;
            ansc = tempc;
        }
    }

    for (int i = 0; i < ansb; i++) {
        printf("%s", b);

        for (int j = 0; j < 26; j++) {
            cnta[j] -= cntb[j];
        }
    }

    for (int i = 0; i < ansc; i++) {
        printf("%s", c);

        for (int j = 0; j < 26; j++) {
            cnta[j] -= cntc[j];
        }
    }

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < cnta[i]; j++) {
            printf("%c", i + 'a');
        }
    }

    puts("");

    return 0;
}
