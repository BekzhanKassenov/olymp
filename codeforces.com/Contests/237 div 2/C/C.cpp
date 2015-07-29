/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))

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
const int maxn = 100010;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

int n, k, x, prsize, ptr, degree[maxn], maxlev, edge_cnt;
vector <int> level[maxn];
stringstream ss;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &k);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        level[x].push_back(i + 1);
        maxlev = max(x, maxlev);
    }
    
    for (int i = 1; i <= maxlev; i++) {
        ptr = 0;
        prsize = level[i - 1].size();
        
        for (size_t j = 0; j < level[i].size(); j++) {
            if (ptr < prsize)
                ss << level[i - 1][ptr] << ' ' << level[i][j] << endl;
            else {
                cout << -1;
                return 0;
            }
            
            degree[level[i - 1][ptr]]++;
            degree[level[i][j]]++;
            
            edge_cnt++;
            
            if (degree[level[i - 1][ptr]] == k)
                ptr++;
            
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (degree[i] > k || degree[i] == 0) {
            cout << -1;
            return 0;
        }
    }
    
    cout << n - 1 << endl << ss.str();

    return 0;
}
