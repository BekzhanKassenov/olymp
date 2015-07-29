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
const int maxn = 5050;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

int a[maxn], b[maxn], n, m;
int g, ans, cur_l, cur_r, f[maxn];

int gcd(int a, int b) {
    while (a && b) {
        a %= b;
        swap(a, b);
    }
    
    return a + b;
}

int func(int num) {
    int k = sqrt(num);

    int res = 0;
    
    for (int i = 2; i <= k; i++) {
        bool is_bad = binary_search(b, b + n, i);
        
        while (num % i == 0) {
            if (is_bad)
                res--;
            else
                res++;
                
            num /= i;
        }
    } 
    
    if (num > 1) {
        if (binary_search(b, b + n, num))
            res--;
        else
            res++;
    }
    
    return res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);
   
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
        
    for (int i = 0; i < m; i++)
        scanf("%d", b + i);
    
    for (int i = 0; i < n; i++) {
        f[i] = func(a[i]);
        cur_r += f[i];
    }
    
    ans = cur_r;
    
    for (int i = 0; i < n; i++) {
        g = gcd(g, a[i]);
        
        if (g == 1)
            break;        
        
        cur_l += f[i] - func(g);
        cur_r -= f[i];
        
        ans = max(ans, cur_l + cur_r);
    }
    
    printf("%d\n", ans);
    
    return 0;
}
