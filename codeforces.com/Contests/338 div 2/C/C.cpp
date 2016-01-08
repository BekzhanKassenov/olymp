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
const int MAXN = 2110;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

char t[MAXN];
char s1[MAXN], s2[MAXN];
int lcp1[MAXN][MAXN], lcp2[MAXN][MAXN];
int lens, lent;
int dp[MAXN];
pair <int, int> par[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    gets(s1);
    lens = strlen(s1);

    strcpy(s2, s1);
    reverse(s2, s2 + lens);

    gets(t);
    lent = strlen(t);

    for (int i = lens - 1; i >= 0; i--) {
        for (int j = lent - 1; j >= 0; j--) {
            if (s1[i] == t[j]) {
                lcp1[i][j] = (i + 1 < lens && j + 1 < lent) ? lcp1[i + 1][j + 1] + 1 : 1;
            } else {
                lcp1[i][j] = 0;
            }

            if (s2[i] == t[j]) {
                lcp2[i][j] = (i + 1 < lens && j + 1 < lent) ? lcp2[i + 1][j + 1] + 1 : 1;
            } else {
                lcp2[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < lent; i++) {
        dp[i] = INF;
    }

    for (int i = 0; i < lent; i++) {
        int maxpos1 = 0;
        for (int j = 0; j < lens; j++) {
            if (lcp1[maxpos1][i] < lcp1[j][i]) {
                maxpos1 = j;
            }
        }

        int maxpos2 = 0;
        for (int j = 0; j < lens; j++) {
            if (lcp2[maxpos2][i] < lcp2[j][i]) {
                maxpos2 = j;
            }
        }

        pair <int, int> ans;

        int* inc = NULL;
        int delta = 0;
        if (lcp1[maxpos1][i] > lcp2[maxpos2][i]) {
            ans = make_pair(maxpos1, maxpos1);
            inc = &ans.second;
            delta = 1;
        } else {
            ans = make_pair(lens - 1 - maxpos2, lens - 1 - maxpos2);
            inc = &ans.second;
            delta = -1;
        }

        int prevdp = (i > 0) ? dp[i - 1] : 0;

        for (int j = i; j < i + max(lcp1[maxpos1][i], lcp2[maxpos2][i]); j++) {
            if (dp[j] > prevdp + 1) {
                dp[j] = prevdp + 1;
                par[j] = ans;
            }

            *inc += delta;
        }
    }

    if (dp[lent - 1] == INF) {
        puts("-1");
        return 0;
    }

    vector <pair <int, int> > res;
    int pos = lent - 1;

    while (pos >= 0) {
        res.push_back(par[pos]);

        int mx = max(par[pos].first, par[pos].second);
        int mn = min(par[pos].first, par[pos].second);

        pos -= mx - mn + 1;
    }

    printf("%d\n", dp[lent - 1]);
    reverse(all(res));
    for (auto p: res) {
        printf("%d %d\n", p.first + 1, p.second + 1);
    }


    return 0;
}
