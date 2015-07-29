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
#define File "legendary"

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

map <PII, int> Map;

int gcd(int a, int b) {
    while (a && b) {
        a %= b;
        swap(a, b);
    }
    
    return a + b;
}

int sign(int n) {
    return (n > 0) - (n < 0);
}

void normalize(PII& a) {
    if (a.F == 0) {
        a.S = sign(a.S);
    } else if (a.S == 0) {
        a.F = sign(a.F);
    } else {
        int g = gcd(abs(a.F), abs(a.S));
        a.F /= g;
        a.S /= g;
    }
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        Map.clear();
        
        PII a;
        
        for (int i = 0; i < n; i++) {
            cin >> a.F >> a.S;
            normalize(a);
            Map[a]++;
        }
        
        if (Map.size() == 1) {
            cout << "Great! " << n << " targets with one shot!" << endl;
        } else {
            cout << Map.size() << " shoots!" << endl;
        }
    }
    
    return 0;
    }
