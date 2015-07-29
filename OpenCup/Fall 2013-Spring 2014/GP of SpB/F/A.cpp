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
#define y0 y0_lal
#define y1 y1_lal
#define yn en_lal
#define j0 j0_lal
#define j1 j1_lal
#define jn jn_lal
#define next next_lal
#define prev prev_lal
#define File "intset"

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
double soch(int m, int n){
    int mn = min(m, n-m);
    double niz = 1.0;
    
    for (int j = 1; j <= mn; ++j)
        niz *= (double)(n-mn+j)/(double)(j);
    
    return niz;
}
double get_up(double prev, int top, int bot){
    return prev*(double)(bot - top + 1)/(double)(top);
}
double get_down(double prev, int top, int bot){
    return double(top + 1) / double(bot - top) * prev;
}
int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    int n, m, l;
    
    double niz = 1.0, verh1 = 1.0, verh2 = 1.0, sum = 0.0;
    
    cin >> n >> l >> m;
    
    niz = soch(m, n);
    
    bool cont = 0;
    int mn = min(m, l); 
    int i = mn-1;
    
    verh1 = soch(m-mn, n-l);
    
    verh2 = soch(mn, l);
    
    sum = verh1 * verh2;
    
    if (sum*2.0 < niz)
        cont = 1;                 

    while (cont && i >= 0) {
        //cout << verh1 << ' ' << verh2 << endl;
        verh1 = get_up(verh1, m - i, n - l);
        verh2 = get_down(verh2, i, l);
        sum += verh1 * verh2;
        cont = 0;   
        
        if (sum * 2.0 < niz)
            cont = 1;
        
        i--;
    }                     
    cout << i + 1;         
    return 0;
}
