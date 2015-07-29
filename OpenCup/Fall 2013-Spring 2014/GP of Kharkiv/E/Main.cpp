/****************************************
**         Solution by NU #2           **
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
const int maxn = 200020;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

pair <int, ll> a[maxn];
int n;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
        scanf("%d%I64d", &a[i].F, &a[i].S);
        
    sort(a, a + n);
    
    for (int i = 1; i < n; i++)
        if (a[i].F - a[i - 1].F > 3  b) {    
            cout << "No";
            return 0;
        }
        
    

    return 0;
}
