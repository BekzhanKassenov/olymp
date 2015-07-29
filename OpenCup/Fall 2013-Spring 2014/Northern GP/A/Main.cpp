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
#define File "analogous"

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

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    int n;
    
    while ((cin >> n) && n) {
        if (__builtin_popcount(n) > 1) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
            
            vector <int> a(2), b(2);
            
            a[0] = 1;
            a[1] = 4;
            
            b[0] = 2;
            b[1] = 3;
            
            for (int i = 2; i < n; i <<= 1) {
                for (int j = 0; j < i; j++) {
                    a.push_back(b[j] + 2 * i);
                    b.push_back(a[j] + 2 * i);
                }
            }
            
            for (int i = 0; i < n; i++)
                cout << a[i] << ' ';

            cout << endl;
            
            for (int i = 0; i < n; i++)
                cout << b[i] << ' ';
            
            cout << endl;
        }
    }
    
    return 0;
}
