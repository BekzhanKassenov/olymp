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
const int maxa = 1000 * 1000 * 1000;
const int maxart = 32000;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

int a[maxn], b[maxn], n, m;
int pref[maxn];
int isprime[maxart];
vector <int> primes;

int gcd(int a, int b) {
    while (a && b) {
        a %= b;
        swap(a, b);
    }
    
    return a + b;
}

int func(int num) {
    int N = num;
    int res = 0;
    
    for (int p : primes) {
        if (p * p > N) {
            break;
        }
        bool is_bad = binary_search(b, b + m, p);        
        while (num % p == 0) {
            if (is_bad)
                res--;
            else
                res++;
                
            num /= p;
        }
    } 
    
    if (num > 1) {               
        if (binary_search(b, b + m, num))
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

    for (int i = 0; i < maxart; i++) {
        isprime[i] = true;
    }
    isprime[0] = false;
    isprime[1] = false;
    for (int i = 2; i < maxart; i++) {
        if (!isprime[i]) {
            continue;
        }
        primes.push_back(i);
        for (int j = i * i; j < maxart; j += i) {
            isprime[j] = false;
        }
    }
    
    pref[0] = a[0];
    for (int i = 1; i < n; i++) {
        pref[i] = gcd(pref[i - 1], a[i]);
    }

    int accum = 1;
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (func(pref[i] / accum) < 0) {
            accum = pref[i];
        }
        ans += func(a[i] / accum);
    }
    printf("%d\n", ans);
    
    return 0;
}
