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
const int MAXN = 2010;
const int di[] = {1, -1,  1, -1};
const int dj[] = {1, -1, -1,  1};

template <typename T>
inline T sqr(T n) {
    return n * n;
}

char s[MAXN][MAXN];
bool used[MAXN][MAXN];
int n, m;

bool ok(int i, int j) {
    return 0 <= i && i < n &&
           0 <= j && j < m;
}

void bfs(int i, int j) {
    vector <int> I, J;
    I.push_back(i);
    J.push_back(j);

    used[i][j] = true;

    for (size_t q = 0; q < I.size(); q++) {
        int curi = I[q];
        int curj = J[q];

        for (int k = 0; k < 4; k++) {
            int ti = curi + di[k];
            int tj = curj + dj[k];

            if (!ok(ti, tj)) {
                continue;
            }

            int cnt = 0;
            int newi = -1;
            int newj = -1;

            for (int ii = min(curi, ti); ii <= max(curi, ti); ii++) {
                for (int jj = min(curj, tj); jj <= max(curj, tj); jj++) {
                    if (s[ii][jj] == '*') {
                        cnt++;
                        newi = ii;
                        newj = jj;
                    }
                }
            }

            if (cnt == 1) {
                I.push_back(newi);
                J.push_back(newj);

                //cout << cnt << ' ' << newi << ' ' << newj << ' ' << ti << ' ' << tj << ' ' << curi << ' ' << curj << endl;
                s[newi][newj] = '.';
                used[newi][newj] = true;
            }
        }
    }   
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d %d\n", &n, &m);
    
    for (int i = 0; i < n; i++) {
        gets(s[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!used[i][j] && s[i][j] == '.') {
                bfs(i, j);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        puts(s[i]);
    }

    return 0;
}
