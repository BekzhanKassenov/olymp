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
#define File "flights"

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

int g[maxn][maxn];
int sum[maxn];
PII edge[100010];

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    srand(time(NULL));
    
    int n, m;
    
    while ((cin >> n >> m) && (n || m)) {
        vector <int> num(m);
        
        for (int i = 0; i < m; i++)
            cin >> edge[i].F >> edge[i].S;
        
        cycle: 
        for (int i = 0; i < m; i++)
            num[i] = i + 1;
            
        random_shuffle(all(num));
        memset(sum, 0, sizeof sum);
        
        for (int i = 0; i < m; i++) {
            g[edge[i].F][edge[i].S] = g[edge[i].S][edge[i].F] = num[i];
            sum[edge[i].F] += num[i];
            sum[edge[i].S] += num[i];
        }
     
        int cnt = 100;
        
        bool found = false;
        
        while (cnt--) {
            bool flag = false;
            for (int i = 2; i <= n; i++) {
                for (int j = i + 1; j <= n; j++) {
                    if (sum[i] == sum[j]) {
                        int previ = g[1][i];
                        int prevj = g[1][j];
                        
                        sum[i] -= previ;
                        sum[i] += prevj;
                        
                        sum[j] -= prevj;
                        sum[j] += previ;
                        
                        g[1][i] = prevj;
                        g[i][1] = prevj;
                        
                        g[1][j] = previ;
                        g[j][1] = previ;
                        flag = true;
                    }
                }
            }

            if (!flag) {
                found = true;
                break;
            }
        }
        
        for (int i = 2; i <= n; i++)
            if (sum[i] == sum[1])
                goto cycle;
        
        if (found) {
            cout << "Yes" << endl;
            
            for (int i = 0; i < m; i++) {
                cout << g[edge[i].F][edge[i].S] << ' ';
            }
            
            cout << endl;
        } else {
            cout << "No" << endl;
        }
    }
    
    return 0;
}
