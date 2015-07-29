/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))
#define File "alphabet"

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);
const int maxn = 100;
const int m = 20;
const int maxc = 1010;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

struct item {
    int num;
    char c;
    
    item() { }
    
    item(int num, char c) : num(num), c(c) { }
    
    bool operator < (const item& it) const {
        if (c != it.c)
            return c > it.c;
            
        return num < it.num;
    }
};

char c[maxn][m + 1], letter[maxc];
int n, cmp[maxn][m], last = 1, lastcmp;
bool used[maxc];

int dx[] = {1, 0, 0, -1};
int dy[] = {0, 1, -1, 0};
set <item> g[maxc];
vector <int> order[maxn];

bool ok(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int x, int y) {
    cmp[x][y] = last;
    
    for (int i = 0; i < 4; i++) {
        int tx = x + dx[i];
        int ty = y + dy[i];
        
        if (ok(tx, ty) && !cmp[tx][ty] && c[tx][ty] == c[x][y])
            dfs(tx, ty);
    }
}

void build() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (c[i][j] != '.') {
                for (int k = i + 1; k < n; k++)
                    if (c[k][j] != '.' && cmp[k][j] != cmp[i][j]) {
                        g[cmp[i][j]].insert(item(cmp[k][j], c[k][j]));
                        break;
                    }
            }
        }
    }
}

bool cmpvx (int v1, int v2) {
    return (letter[v1] < letter[v2]);
}

void dfs(int v) {
    used[v] = true;
    vector <int> vx;
    
    for (set <item> :: iterator it = g[v].begin(); it != g[v].end(); it++) {
        if (!used[it -> num]) {
            vx.push_back (it -> num);
            //dfs(it -> num);
        }
    }

    sort (vx.begin(), vx.end(), &cmpvx);
    
    for (int i = 0; i < (int)vx.size(); i++)
        dfs (vx[i]);
    
    order[lastcmp].push_back(v);
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
        scanf("%s", c[i]);
        
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            if (c[i][j] != '.' && !cmp[i][j]) {
                dfs(i, j);
                letter[last] = c[i][j];
                last++;
            }
    }
    
    build();
    
    for (int i = 1; i < last; i++) {
        if (!used[i]) {
            dfs(i);
            lastcmp++;
        }
    }
    
    for (int i = 0; i < lastcmp; i++)
        reverse(all(order[i]));
        
    for (int i = 1; i < last; i++) {
        int mn = -1;
        
        for (int j = 0; j < lastcmp; j++) {
            if (!order[j].empty() && (mn == -1 || letter[order[mn].back()] > letter[order[j].back()]))
                mn = j;
        }
        
        printf("%c", letter[order[mn].back()]);
        order[mn].pop_back();
    }
    
    return 0;
}
