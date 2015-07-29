/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))
#define File "death"

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
const int maxn = 1010;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

int a[maxn][maxn], n, m;
int last_comp, comp[maxn][maxn], comp_owner[maxn * maxn], comp_size[maxn * maxn];
bool used[maxn][maxn], inque[maxn * maxn];

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

bool ok(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

struct edge {
    int from, to;
    
    edge() { }
    
    edge(int a, int b) : from(min(a, b)), to(max(a, b)) { }
    
    inline bool operator < (const edge& ed) const {
        return (from != ed.from) * (from < ed.from) + (from == ed.from) * (to < ed.to);
    }
};

struct Queue {
    int arr[maxn * maxn];
    
    int head, tail;
    
    Queue() : head(0), tail(0) { }
    
    void push(int val) {
        arr[tail++] = val;
    }
    
    int front() {
        return arr[head];
    }
    
    void pop() {
        head++;
    }
    
    bool empty() {
        return head >= tail;
    }
    
    void clear() {
        head = tail = 0;
    }
};

set <edge> Set;
vector <int> g[maxn * maxn];
Queue q1, q2;

inline void bfs_enum(int x, int y) {
    q1.clear();
    q2.clear();
    
    q1.push(x);
    q2.push(y);
    
    used[x][y] = true;

    while (!q1.empty()) {
        x = q1.front();
        y = q2.front();

        q1.pop();
        q2.pop();
        
        comp[x][y] = last_comp;
        comp_size[last_comp]++;
    
        for (int i = 0; i < 4; i++) {
            int tx = x + dx[i];
            int ty = y + dy[i];
        
            if (ok(tx, ty) && !used[tx][ty] && a[tx][ty] == a[x][y]) {
                q1.push(tx);
                q2.push(ty);
                used[tx][ty] = true;
            }
        }  
    }
}

inline void dfs_build(int x, int y) {
    q1.clear();
    q2.clear();
    
    q1.push(x);
    q2.push(y);
    
    used[x][y] = true;

    while (!q1.empty()) {
        x = q1.front();
        y = q2.front();
        
        q1.pop();
        q2.pop();
        
        for (int i = 0; i < 4; i++) {
            int tx = x + dx[i];
            int ty = y + dy[i];
        
            if (ok(tx, ty)) {
                if (a[tx][ty] != a[x][y]) {
                    edge n_edge(comp[x][y], comp[tx][ty]);
                
                    if (!Set.count(n_edge)) {
                        Set.insert(n_edge);
                        g[comp[x][y]].push_back(comp[tx][ty]);
                        g[comp[tx][ty]].push_back(comp[x][y]);
                    }
                }
            
                if (!used[tx][ty]) {
                    q1.push(tx);
                    q2.push(ty);
                    used[tx][ty] = true;
                }
            }
        }
    }
}

int used1[maxn * maxn], last_us;

inline int bfs_ans(int cmp, int col1, int col2) {
    q1.clear();
    q1.push(cmp);
    int res = 0;
    last_us++;
    
    used1[cmp] = last_us;
    
    while (!q1.empty()) {
        int cur = q1.front();
        q1.pop();
        
        res += comp_size[cur];
        
        int last = 0;
        
        for (size_t i = 0; i < g[cur].size(); i++) {
            int to = g[cur][i];
        
            if (comp_owner[to] != col1 && comp_owner[to] != col2) {
                g[cur][last++] = to;
                continue;
            }
        
            edge ed(cur, to);
        
            if (Set.count(ed)) {
                Set.erase(ed);
                
                if (used1[to] != last_us) {
                    q1.push(to);
                    used1[to] = last_us;
                }
            }
        }
        
        g[cur].resize(last);
    }
    
    return res;
}

int read_int() {
    char c;
    
    do {
        c = getc(stdin);
    } while (c < '0' || c > '9');
    
    int res = 0;
    
    do {
        res = res * 10 + (c - '0');
        c = getc(stdin);
    } while (c >= '0' && c <= '9');
    
    return res;
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);

    n = read_int();
    m = read_int();
    
    bool flag = false;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = read_int();
            flag |= (a[i][j] != a[0][0]);
        }
    }
    
    if (!flag) {
        printf("%d\n%d %d", n * m, a[0][0], a[0][0]);
        return 0;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!used[i][j]) {
                bfs_enum(i, j);
                comp_owner[last_comp] = a[i][j];
                last_comp++;
            }
        }
    }
    
    memset(used, false, sizeof used);
    
    dfs_build(0, 0);

    int ans = 0;
    
    int ans_owner1 = 0, ans_owner2 = 0;
    
    while (!Set.empty()) {
        edge cur = *Set.begin();
        
        int temp = bfs_ans(cur.from, comp_owner[cur.from], comp_owner[cur.to]);
        
        if (temp > ans) {
            ans = temp;
            ans_owner1 = comp_owner[cur.from];
            ans_owner2 = comp_owner[cur.to];
        }
    }
    
    printf("%d\n%d %d\n", ans, min(ans_owner1, ans_owner2), max(ans_owner1, ans_owner2));
    
    return 0;
}
