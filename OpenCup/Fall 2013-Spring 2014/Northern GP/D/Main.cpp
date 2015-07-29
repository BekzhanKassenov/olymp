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
#define File "drunkard"

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

int gcd(int a, int b) {
    while (a && b) {
        a %= b;
        swap(a, b);
    }
    
    return a + b;
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    int p, q;
    
    while ((cin >> p >> q) && p) {    
        p = q - p;
        int gc = gcd(q, p);
        q /= gc;
        p /= gc;
        
        vector <int> a(q + 1);
        
        a[0] = q + 1;
        a[q] = q;
        
        a[q - p] = 1;
        int num = 2;
        
        for (int i = 1; i < q; i++)
            if (a[i] == 0)
                a[i] = num++;
                
        vector <PII> g(q + 1);
        
        for (int i = 1; i < q; i++) {
            g[a[i]].F = a[i - 1];
            g[a[i]].S = a[i + 1];
        }
        
        cout << q + 1 << endl;
        
        for (int i = 1; i < q; i++)
            cout << g[i].F << ' ' << g[i].S << endl;
    }
    
    return 0;
}
