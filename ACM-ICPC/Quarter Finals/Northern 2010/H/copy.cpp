/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "horrible"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 110;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

bool know1[MAXN][MAXN];
bool know2[MAXN][MAXN];
int n;
vector <pair <int, int> > ans;

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    scanf("%d", &n);

    if (n == 1) {
        puts("1");
        puts("1 0");
        return 0;
    }

    memset(know1, true, sizeof know1);

    ans.emplace_back(1, -2);
    know2[1][2] = true;

    int i1 = 1, j1 = 1;
    int i2 = 1, j2 = 1;

    for (int i = 1; i <= n; i++) {
        ans.emplace_back(i, 0);

        for (int j = 1; j <= n; j++) {
            know1[j][i] = false;
            know2[j][i] = true;
        }

        bool who = false;
        bool found = true;

        while (found) {
            if (who) {
                found = false;
                while (j1 <= n && !found) {
                    while (i1 <= n && !found) {
                        if (!know1[i1][j1]) {
                            found = true;
                        }

                        i1++;
                    }

                    if (i1 > n) {
                        i1 = 1;
                        j1++;
                    }
                }

                if (found) {
                    ans.emplace_back(i1, j1);
                    know1[i1][j1] = true;
                }
            } else {
                found = false;
                while (j2 <= n && !found) {
                    while (i2 <= n && !found) {
                        if (!know1[i2][j2]) {
                            found = true;
                        }

                        i2++;
                    }

                    if (i2 > n) {
                        i2 = 1;
                        j2++;
                    }
                }

                if (found) {
                    ans.emplace_back(i2, j2);
                    know1[i2][j2] = true;
                }
            }

            who ^= 1;
        }
    }

    printf("%d\n", ans.size());

    for (auto res: ans) {
        printf("%d %d\n", res.first, res.second);
    }

    return 0;
}
