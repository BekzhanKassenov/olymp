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

ll n;
vector <int> rep;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    cin >> n;
    
    while (n) {
        rep.push_back(n % 2);
        n /= 2;
    }
    
    int cnt = 0, pos = 0;
    
    for (size_t i = 0; i < rep.size(); i++) {
        if (rep[i] == 0) {
            if (cnt > 1) {
                rep[i] = 1;
                rep[pos] = -1;
                
                for (size_t j = pos + 1; j < i; j++)
                    rep[j] = 0;
            
                cnt = 1;
                pos = i;
            } else {
                cnt = 0;
                pos = i;
            }
        } else {
            if (cnt == 0)
                pos = i;
            cnt++;
        }
    }
    
    if (cnt > 1) {
        rep.push_back(1);
        rep[pos] = -1;
        
        for (size_t j = pos + 1; j < rep.size() - 1; j++)
            rep[j] = 0;
    }
    
    reverse(all(rep));
    
    for (size_t i = 0; i < rep.size(); i++)
        cout << rep[i] << ' ';
    
    return 0;
}
