/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "japanese"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 500;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;
char s[MAXN][MAXN];
char ans[MAXN][MAXN];
vector <int> row[MAXN], col[MAXN];

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    scanf("%d%d\n", &n, &m);

    for (int i = 0; i < n; i++) {
        gets(s[i]);
    }

    int width = 0, height = 0;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'X') {
                cnt++;
            } else {
                if (cnt != 0) {
                    row[i].push_back(cnt);
                    cnt = 0;
                }
            }
        }

        if (cnt != 0) {
            row[i].push_back(cnt);
        }

        width = max(width, (int)row[i].size());
    }

    for (int j = 0; j < m; j++) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i][j] == 'X') {
                cnt++;
            } else {
                if (cnt != 0) {
                    col[j].push_back(cnt);
                    cnt = 0;
                }
            }
        }

        if (cnt != 0) {
            col[j].push_back(cnt);
        }

        height = max(height, (int)col[j].size());
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            ans[i][j] = '*';
        }
    }

    for (int i = height; i < n + height; i++) {
        int size = (int)row[i - height].size();
        for (int j = 0; j < width - size; j++) {
            ans[i][j] = '_';
        }

        int ptr = 0;
        for (int j = width - size; j < width; j++) {
            ans[i][j] = row[i - height][ptr++] + '0';
        }
    }

    for (int j = width; j < m + width; j++) {
        int size = (int)col[j - width].size();
        for (int i = 0; i < height - size; i++) {
            ans[i][j] = '_';
        }

        int ptr = 0;
        for (int i = height - size; i < height; i++) {
            ans[i][j] = col[j - width][ptr++] + '0';
        }
    }

    for (int i = height; i < n + height; i++) {
        for (int j = width; j < m + width; j++) {
            ans[i][j] = '.';
        }
    }

    for (int i = 0; i < n + height; i++) {
        puts(ans[i]);
    }

    return 0;
}
