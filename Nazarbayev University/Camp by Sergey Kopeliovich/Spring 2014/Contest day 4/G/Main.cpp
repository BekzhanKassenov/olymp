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
#define File "hamming"

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
const double lim = 2e18;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

long long p1, p2, p3;
int n;

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    cin >> p1 >> p2 >> p3 >> n;
    
    double n1, n2, n3;

    n1 = 1;
    vector <double> vec;
    
    for (int i = 0; i < 64; i++) {
        n2 = 1;
        for (int j = 0; j < 64; j++) {
            n3 = 1;
            for (int k = 0; k < 64; k++) { 
                vec.push_back(n1 * n2 * n3);
                n3 *= p3;
                if (n3 > lim || n3 * n2 > lim || n3 * n2 * n1 > lim)
                    break;
            }
            
            n2 *= p2;
            if (n2 > lim || n2 * n1 > lim)
                break;
        }
        
        n1 *= p1;
        
        if (n1 > lim)
            break;
    }
    
    sort(all(vec));
    
    cout << (ll)(vec[n] + .5);
    
    return 0;
}
