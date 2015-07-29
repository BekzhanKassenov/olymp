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

char c[maxn][m + 1];
int n;
bool g[maxn][maxn], used[maxn], has[maxn];

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
        scanf("%s", c[i]);
        
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (c[i][j] == '.')
                continue;
              
            has[(int)(c[i][j] - 'A')] = true;
                
            for (int k = i + 1; k < n; k++) {
                if (c[k][j] == '.' || c[k][j] == c[i][j])
                    continue;
                    
                g[c[i][j] - 'A'][c[k][j] - 'A'] = true;
            }
        }
    }
    
    while (true) {
        int num = -1;
        
        for (int i = 0; i < 26 && num == -1; i++) {
            if (!used[i] && has[i]) {
                bool can = true;
                
                for (int j = 0; j < 26; j++) 
                    can &= (!g[i][j]);
                
                if (can) 
                    num = i;
            }
        }
        
        if (num == -1)
            break;
        
        putchar(num + 'A');
        used[num] = true;
        for (int i = 0; i < 26; i++)
            g[i][num] = false;
    }
    
    return 0;
}
