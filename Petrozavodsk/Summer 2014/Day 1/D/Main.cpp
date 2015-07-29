/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "domino-tiling"

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

char let[] = {'l', 'r', 'u', 'd'};
int dx[] = {0,  0,  1, -1};
int dy[] = {1, -1,  0,  0};

char a[MAXN][MAXN], b[MAXN][MAXN], temp[MAXN];
int num[MAXN][MAXN], n, m, last;

bool used[MAXN][MAXN];
int ans_last, cost;
vector < pair < int, int > > ans[MAXN * MAXN];

void move(int& i, int& j, char ch) {
    for (int k = 0; k < 4; k++) {
        if (ch == let[k]) {
            i += dx[k];
            j += dy[k];
            return;
        }
    }
}

void dfs(int i, int j) {
    if (used[i][j])
        return;

    used[i][j] = true;
    ans[ans_last].push_back(MP(i, j));

    cost += 2;
    move(i, j, a[i][j]);

    used[i][j] = true;
    ans[ans_last].push_back(MP(i, j));

    move(i, j, b[i][j]);

    dfs(i, j);
}

bool is(char ch) {
    return ch == 'l' || ch == 'u';
}
                           
int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    scanf("%d%d\n", &n, &m);

    for (int i = 0; i < n; i++)
        gets(a[i]);

    gets(temp);

    for (int i = 0; i < n; i++)
        gets(b[i]);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!used[i][j] && is(a[i][j]) && a[i][j] != b[i][j]) {
                dfs(i, j);
                ans_last++;
            }
        }
    }

    printf("%d %d\n", ans_last, cost);

    for (int i = 0; i < ans_last; i++) {
        printf("%u ", ans[i].size());

        for (size_t j = 0; j < ans[i].size(); j++) {
            printf("%d %d ", ans[i][j].F + 1,
                             ans[i][j].S + 1);

        }
        puts("");
    }
    
    return 0;
}
