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
#define File "exp"

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
const int maxn = 110;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

vector <int> g[maxn];
int n, m, x, degree[maxn], color[maxn], used[maxn];

void solve(int col, int& ans, vector <int>& res) {
    ans = 0;
    
    memset(degree, 0, sizeof degree);
    memset(used, 0, sizeof used);
    
    for (int i = 0; i < n; i++)
        for (size_t j = 0; j < g[i].size(); j++)
            degree[g[i][j]]++;
            
    queue <int> *q1, *q2;
    
    q1 = new queue <int> ();
    q2 = new queue <int> ();
    
    for (int i = 0; i < n; i++) {
        if (degree[i] == 0) {
            if (color[i] == col)
                q1 -> push(i);
            else 
                q2 -> push(i);

            used[i] = true;
        }
    }
    
    while (!(q1 -> empty()) || !(q2 -> empty())) {
        while (!(q1 -> empty())) {
            int cur = q1 -> front();
            
            res.push_back(cur);
            q1 -> pop();
        
            for (size_t i = 0; i < g[cur].size(); i++) {
                int par = g[cur][i];
            
                degree[par]--;
            
                if (!used[par] && degree[par] == 0) {
                    if (color[par] == col)
                        q1 -> push(par);
                    else
                        q2 -> push(par);
                    
                    used[par] = true;
                }
            }
        }
        col ^= 1;
        
        if (!q2 -> empty())
            ans++;
        
        swap(q1, q2);
    }
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);

    scanf("%d", &n); 
    
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &color[i], &m);
        
        for (int j = 0; j < m; j++) {
            scanf("%d", &x);
            x--;
            g[x].push_back(i);
        }
    }
    
    int ans1, ans2;
    vector <int> res1, res2;
    
    solve(1, ans1, res1);
    solve(0, ans2, res2);
    
    if (ans1 < ans2 || res2.empty()) {
        printf("%d\n", ans1);    
    
        for (size_t i = 0; i < res1.size(); i++) {
            printf("%d ", res1[i] + 1);
        }
    } else {
        printf("%d\n", ans2);    
    
        for (size_t i = 0; i < res2.size(); i++) {
            printf("%d ", res2[i] + 1);
        }
    }
    
    return 0;
}
