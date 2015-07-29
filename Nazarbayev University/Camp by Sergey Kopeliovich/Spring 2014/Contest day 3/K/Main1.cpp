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
#define File "succession"

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

/*struct realn {
    long double num, den;
    
    realn() : num(0), den(1) { }
    
    realn(long double num, long double den) : num(num), den(den) { 
        if (realn :: num == 0)
            realn :: den = 1;
        else {
            while (!(realn :: num & 1)) {
                realn :: num >>= 1;
                realn :: den >>= 1;
            }
        }
    }
    
    realn operator + (const realn& rhs) const {
        long double dn = max(den, rhs.den);
        long double nm = dn / den * num + dn / rhs.den * rhs.num;
        
        return realn(nm, dn);
    }
    
    bool operator < (const realn& rhs) const {
        long double dn = max(den, rhs.den);
        long double num1 = dn / den * num;
        long double num2 = dn / rhs.den * rhs.num;
        
        return num1 < num2;
    }
};*/

int n, m;
map <string, pair <string, string> > Map;
map <string, bool> calced;
map <string, ld> blood;

ld get_bl(const string& str) {
    if (calced[str])
        return blood[str];
        
    calced[str] = true;
    
    blood[str] = get_bl(Map[str].F) / 2 + get_bl(Map[str].S) / 2;
    
    return blood[str];
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    int n, m;
    cin >> n >> m;
    
    string king;
    cin >> king;
    blood[king] = 1ll << 51;
    calced[king] = true;
    
    for (int i = 0; i < n; i++) {
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;
        Map[s1] = MP(s2, s3);
    }
    
    string res;
    long double ans = 0;
    string temp;
    
    for (int i = 0; i < m; i++) {
        cin >> temp;
        ld bl = get_bl(temp);
        
        if (bl >= ans) {
            ans = bl;
            res = temp;
        }
    }
    
    cout << res;
    
    return 0;
}
