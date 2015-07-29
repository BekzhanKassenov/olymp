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
const ll lim = (ll) 1e14;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

ll gcd(ll a, ll b) {
    while (a && b) {
        a %= b;
        swap(a, b);
    }
    
    return a + b;
}

ll my_pow(ll a, int st) {
    ll res = 1;
    
    for (int i = 0; i < st; i++)
        res *= a;
        
    return res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    int a, b;
    cin >> a >> b;
    
    int gg = gcd(a, b);
    a /= gg;
    b /= gg;
    
    vector <ll> res;
    
    for (int st1 = 0; st1 < 50; st1++) {
        for (int st2 = 0; st2 <= 30; st2++) {
            for (int st3 = 0; st3 <= 21; st3++) {
                ll n = my_pow(2, st1);
                if (n > lim)
                    continue;
                    
                ll k = my_pow(3, st2);
                
                if (k > lim || ((double)n) * k > lim)
                    continue;
                    
                n *= k;
                
                k = my_pow(5, st3);
                
                if (k > lim || ((double)n) * k > lim)
                    continue;
                    
                n *= k;
                
                ll num = 1;
                
                if (st1)
                    num *= (my_pow(2, st1 + 1) - 1);
                    
                if (st2) {
                    num *= (my_pow(3, st2 + 1) - 1);
                    num /= 2;
                }
                    
                if (st3) {
                    num *= (my_pow(5, st3 + 1) - 1);
                    num /= 4;
                }
                
                ll g = gcd(n, num);
                ll denom = n / g;
                num /= g;
                
                if (num == a && denom == b) {
                    res.push_back(n);
                }
            }
        }
    }

    cout << res.size() << endl;

    for (size_t i = 0; i < res.size(); i++)
        cout << res[i] << endl; 

    return 0;
}
