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

pair <int, int> get_min(bool know[MAXN][MAXN]) {
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= n; i++) {
            if (i != j && !know[i][j]) {
                return make_pair(i, j);
            }
        }
    }

    return make_pair(-1, -1);
}

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

    ans.emplace_back(2, -1);
    know2[2][1] = true;

    /*
    int i1 = 1, j1 = 1;
    int i2 = 1, j2 = 1;
    */

    for (int i = 1; i <= n; i++) {
        ans.emplace_back(i, 0);

        for (int j = 1; j <= n; j++) {
            know1[j][i] = false;
            know2[j][i] = true;
        }

        /*
        for (int ii = 1; ii <= n; ii++) {
            for (int jj = 1; jj <= n; jj++) {
                cout << know1[ii][jj];
            }
            cout << endl;
        }
        cout << endl;
        for (int ii = 1; ii <= n; ii++) {
            for (int jj = 1; jj <= n; jj++) {
                cout << know2[ii][jj];
            }
            cout << endl;
        }
        cout << endl;
        cout << endl;
        */

        bool who = false;
        bool found = true;

        while (found) {
            if (!who) {
                pair <int, int> p(get_min(know1));
                found = false;
                //cerr << p.first << ' ' << p.second << endl;

                if (p != make_pair(-1, -1)) {
                    ans.push_back(p);
                    know1[p.first][p.second] = true;
                    found = true;
                }

            } else {
                pair <int, int> p(get_min(know2));
                found = false;

                if (p != make_pair(-1, -1)) {
                    know2[p.first][p.second] = true;
                    
                    p.second *= -1;
                    ans.push_back(p);
                    
                    found = true;
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
