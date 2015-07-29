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
#define File "table"

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

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

char a[500][500];
int n, m, x;

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    cin >> n;
    
    for (int i = 0, pos = 2; i < n; i++, pos += 2) {
        int m;
        cin >> m;
        
        int jpos = 0;
        for (int j = 0; j < m; j++) {
            cin >> x;
            
            a[pos][jpos++] = '|';
            
            while (x--) {
                a[pos][jpos++] = ' ';
            }
        }
        a[pos][jpos++] = '|';
    }
    
    for (int i = 0, pos = 1; i < n + 1; i++, pos += 2) {
        for (int j = 0; a[pos - 1][j] != '\0' || a[pos + 1][j] != '\0'; j++) {
            if (a[pos - 1][j] == '|' || a[pos + 1][j] == '|')
                a[pos][j] = '+';
            else
                a[pos][j] = '-';
        }
    }
    
    for (int i = 1; i <= 2 * n + 1; i++)
        cout << a[i] << endl;
    
    return 0;
}
