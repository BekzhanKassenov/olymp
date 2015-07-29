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

int b[20][2];
VI v;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    int n;
    ll res = 0; 
    
    cin >> n;

    while (!b[n][1]) {
        res++;
        
        b[0][0]++;
        for (int i = 0; i < n; i++)
            if (b[i][0] > 1)
                b[i][0] = 0, b[i + 1][0]++;
        if (b[n][0])
            b[n][0] = 0, b[1][1]++;
            
        for (int i = 0; i < n; i++)
            if (b[i][1] > 1)
                b[i][1] = 0, b[i + 1][1]++;                            

        v.push_back(b[0][0]);
    }
    
    cout << res << endl;
    
    for (int i = 0; i < (int)v.size(); i++)
        cout << v[i] + 1 << " ";
    
    return 0;
}
