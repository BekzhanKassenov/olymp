/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 100010;
const int LG = 21;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int gcd(int a, int b) {
    while (a && b) {
        a %= b;
        swap(a, b);
    }

    return a + b;
}

int a[MAXN], t[LG][MAXN], n;
int lg[MAXN];
int q, x;
map <int, long long> cnt;
long long ans;

void build() {
    for (int i = 2; i <= n; i++)
        lg[i] = lg[i >> 1] + 1;

    for (int i = 0; i < n; i++)
        t[0][i] = a[i];

    for (int lev = 1; lev < LG; lev++) {
        for (int i = 0; i < n; i++) {
            t[lev][i] = t[lev - 1][i];
            
            int pos = i + (1 << (lev - 1));
            if (pos < n)
                t[lev][i] = gcd(t[lev][i], t[lev - 1][pos]);
        }
    }
}

int get_gcd(int l, int r) {
    r++;
    int lev = lg[r - l];

    return gcd(t[lev][l], t[lev][r - (1 << lev)]);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    build();

    for (int i = 0; i < n; i++) {
        int left = i;

        while (left < n) {
            int r = n, l = left;            
            int g = get_gcd(i, left);    
                                            
            while (r - l > 1) {             
                int mid = (l + r) / 2;      
                                            
                if (get_gcd(i, mid) != g)
                    r = mid;                
                else                        
                    l = mid;                
            }                               
                                            
            long long len = (r - left);     
                                            
            cnt[g] += len;                  
            left = r;                       
        }
    }

    scanf("%d", &q);

    while (q--) {
        scanf("%d", &x);
        printf("%I64d\n", cnt[x]);
    }

    return 0;
}
