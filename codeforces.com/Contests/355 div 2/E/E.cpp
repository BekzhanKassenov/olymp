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
const int MAXN = 1010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
char s[MAXN][MAXN];

bool isGreater(int a, int b, int c, int d) {
    double lhs = a * log(2) + b * log(3);
    double rhs = c * log(2) + d * log(3);

    return lhs > rhs;
}

/*
========================================================================
    Normal
========================================================================
*/
int col[MAXN][MAXN][4];
int row[MAXN][MAXN][4];

void getRow(int r, int from, int to, int res[4]) {
    for (int i = 0; i < 4; i++) {
        res[i] = row[r][to][i];
    }

    if (from > 0) {
        for (int i = 0; i < 4; i++) {
            res[i] -= row[r][from - 1][i];
        }
    }
}

void getCol(int c, int from, int to, int res[4]) {
    for (int i = 0; i < 4; i++) {
        res[i] = col[to][c][i];
    }

    if (from > 0) {
        for (int i = 0; i < 4; i++) {
            res[i] -= col[from - 1][c][i];
        }
    }
}

int bin_search1(int i, int j) {
    static int bufRow[4], bufCol[4];

    int d = 1;
    int l = 1, r = n;

    while (l <= r) {
        int mid = (l + r) / 2;

        if (i - mid < -1 || i + mid >= n + 1 ||
            j - mid < -1 || j + mid >= n + 1) {
            
            r = mid - 1;
            continue;
        }

        getRow(i, j - mid + 1, j + mid - 1, bufRow);
        getCol(j, i - mid + 1, i + mid - 1, bufCol);

        if (bufRow[0] != 0 || bufCol[0] != 0) {
            r = mid - 1;
            continue;
        } else {
            l = mid + 1;
            d = mid;
        }
    }

    return d;
}

/*
========================================================================
    Rotated
========================================================================
*/

int ltr[MAXN][MAXN][4];
int rtl[MAXN][MAXN][4];

void getLtr(int fromI, int fromJ, int toI, int toJ, int res[4]) {
    for (int i = 0; i < 4; i++) {
        res[i] = ltr[toI][toJ][i];
    }

    if (fromI > 0 && fromJ > 0) {
        for (int i = 0; i < 4; i++) {
            res[i] -= ltr[fromI - 1][fromJ - 1][i];
        }
    }
}

void getRtl(int fromI, int fromJ, int toI, int toJ, int res[4]) {
    for (int i = 0; i < 4; i++) {
        res[i] = rtl[toI][toJ][i];
    }

    if (fromI > 0 && fromJ < n - 1) {
        for (int i = 0; i < 4; i++) {
            res[i] -= rtl[fromI - 1][fromJ + 1][i];
        }
    }
}

int bin_search2(int i, int j) {
    static int bufLtr[4], bufRtl[4];

    int d = 1;
    int l = 1, r = n;

    while (l <= r) {
        int mid = (l + r) / 2;

        if (i - mid < -1 || i + mid >= n + 1 ||
            j - mid < -1 || j + mid >= n + 1) {
            
            r = mid - 1;
            continue;
        }

        getLtr(i - mid + 1, j - mid + 1, i + mid - 1, j + mid - 1, bufLtr);
        getRtl(i - mid + 1, j + mid - 1, i + mid - 1, j - mid + 1, bufRtl);

        if (bufLtr[0] != 0 || bufRtl[0] != 0) {
            r = mid - 1;
            continue;
        } else {
            l = mid + 1;
            d = mid;
        }
    }

    return d;
}


/*
========================================================================
    Build
========================================================================
*/

void build() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i > 0) {
                for (int k = 0; k < 4; k++) {
                    col[i][j][k] = col[i - 1][j][k];
                }
            }

            if (j > 0) {
                for (int k = 0; k < 4; k++) {
                    row[i][j][k] = row[i][j - 1][k];
                }   
            }
            
            col[i][j][s[i][j] - '0']++;
            row[i][j][s[i][j] - '0']++;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i > 0 && j > 0) {
                for (int k = 0; k < 4; k++) {
                    ltr[i][j][k] = ltr[i - 1][j - 1][k];
                }
            }

            ltr[i][j][s[i][j] - '0']++;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j >= 0; j--) {
            if (i > 0 && j < n - 1) {
                for (int k = 0; k < 4; k++) {
                    rtl[i][j][k] = rtl[i - 1][j + 1][k];
                }
            }

            rtl[i][j][s[i][j] - '0']++;
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d\n", &n);

    for (int i = 0; i < n; i++) {
        gets(s[i]);
    }

    build();

    int ans2 = 0, ans3 = 0;
    bool found = false;

    int buf1[4], buf2[4];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] == '0') {
                continue;
            }

            int d, cnt2, cnt3;
            found = true;

            /* ================================================
                Normal
            */

            d = bin_search1(i, j);
            getRow(i, j - d + 1, j + d - 1, buf1);
            getCol(j, i - d + 1, i + d - 1, buf2);

            cnt2 = buf1[2] + buf2[2];
            cnt3 = buf1[3] + buf2[3];

            if (s[i][j] == '2') {
                cnt2--;
            }

            if (s[i][j] == '3') {
                cnt3--;
            }

            if (isGreater(cnt2, cnt3, ans2, ans3)) {
                ans2 = cnt2;
                ans3 = cnt3;
            }
            
            /* ================================================
                Rotated
            */
            
            d = bin_search2(i, j);
            getLtr(i - d + 1, j - d + 1, i + d - 1, j + d - 1, buf1);
            getRtl(i - d + 1, j + d - 1, i + d - 1, j - d + 1, buf2);

            cnt2 = buf1[2] + buf2[2];
            cnt3 = buf1[3] + buf2[3];

            if (s[i][j] == '2') {
                cnt2--;
            }

            if (s[i][j] == '3') {
                cnt3--;
            }

//            cerr << i << ' ' << j << ' ' << cnt2 << ' ' << cnt3 << ' ' << d << endl;

            if (isGreater(cnt2, cnt3, ans2, ans3)) {
                ans2 = cnt2;
                ans3 = cnt3;
            }
        }
    }

    /*
    cerr << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cerr << rtl[i][j][1] << ' ';
        }

        cerr << endl;
    }
    */

    if (!found) {
        puts("0");
        return 0;
    }

    int ans = 1;
    for (int i = 0; i < ans2; i++) {
        ans = (1ll * ans * 2) % MOD;
    }

    for (int i = 0; i < ans3; i++) {
        ans = (1ll * ans * 3) % MOD; 
    }

    printf("%d\n", ans);

    return 0;
}
