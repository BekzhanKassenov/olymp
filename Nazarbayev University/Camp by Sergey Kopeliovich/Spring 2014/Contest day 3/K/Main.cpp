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
map <string, vector <string> > g;
map <string, long double> blood;
map <string, bool> inque;

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    int n, m;
    cin >> n >> m;
    
    string king;
    cin >> king;
    blood[king] = 1ll << 51;
    
    for (int i = 0; i < n; i++) {
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;
        g[s2].push_back(s1);
        g[s3].push_back(s1);
    }
    
    queue <string> q;
    q.push(king);
    inque[king] = true;
    
    while (!q.empty()) {
        string cur = q.front();
        q.pop();
        
        long double new_realn = blood[cur];
        new_realn /= 2;

        vector <string> vec = g[cur];
        
        for (size_t i = 0; i < vec.size(); i++) {
            blood[vec[i]] = blood[vec[i]] + new_realn;
            if (!inque[vec[i]]) {
                q.push(vec[i]);
                inque[vec[i]] = true;
            }
        }
    }
    
    string res;
    long double ans = 0;
    string temp;
    
    for (int i = 0; i < m; i++) {
        cin >> temp;
        if (res.empty() || ans < blood[temp]) {
            res = temp;
            ans = blood[temp];
        }
    }
    
//    for (map <string, realn> :: iterator it = blood.begin(); it != blood.end(); it++) {
  //      cout << it -> F << ' ' << (it -> S).num << '/' << (it -> S).den << endl;
    //}
    
    cout << res;
    
    return 0;
}
