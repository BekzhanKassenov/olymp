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
#define File "primesum"

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
bool check(ull x){
    for (ull i = 2; i*i <= x; ++i)
        if (x%i == 0){
            return 0;
            }
    return 1;        
}

ull prec[] = {
11,
101,
1009,
10007,
100003,
1000003,
10000019,
100000007,
1000000007,
10000000019,
100000000003,
10000000000037,
100000000000031,
1000000000000037,
10000000000000061,
100000000000000003,
1000000000000000003};

string res[] = {
"",
"",
"2",
"3",
"2+2",
"2+3",
"2+2+2",
"2+2+3",
"2+2+2+2",
"2+2+2+3",
"2+2+2+2+2",
"11",
"2+2+2+2+2+2",
"11+2"};

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    int j = 16;
    
    ull n;
    
    cin >> n;
    
    while (n >= 13ull){
        while (prec[j] > n)
            --j;
            
        while (n >= prec[j] && n != prec[j] + 1) {
            n -= prec[j];
            cout << prec[j];
            if (n)
                cout << '+';
        }
        
        if (n == prec[j] + 1) {
            j--;
        }
    }
    
    cout << res[n] << endl;
    
    return 0;
}
