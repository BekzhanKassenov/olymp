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
#define File "plates"

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

double a, b, d, r1, r2, _r1, _r2, h;

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    cin >> a >> b >> d >> r1 >> r2 >> _r1 >> _r2 >> h;
    
    if (r1 > r2)
        r2 = r1;
    if (_r1 > _r2)
        _r2 = _r1;
    
    double a1 = d*(r2 - r1)/h, a2 = d*(_r2 - _r1)/h;
    double x1 = 0, y1 = 0, x2 = a, y2 = b;
    if (d <= h){
        x1 += r1 + a1; y1 += r1 + a1;
        x2 -= _r1 + a2; y2 -= _r1 + a2;
    }
    else
    {
        x1 += r2; y1 += r2;
        x2 -= _r2; y2 -= _r2;        
        a1 = a2 = 0;
    }
    if (x1 < 0.0 || x2 < 0.0 || x1 > a || x2 > a || y1 < 0.0 || y2 < 0 || y1 > b || y2 > b || 
        sqrt(sqr(x1-x2) + sqr(y1-y2)) < r2+_r2 || min(a, b) < 2.0*(r1+a1) || min(a, b) < 2.0*(_r1+a2))
        
        cout << "NO";
    else
        cout << "YES";    
        
    return 0;
}
