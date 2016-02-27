/****************************************
**          Solution by NU #2          **
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
const int N = 1000010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int p[N], c[N], pn[N], cn[N], cnt[N], n, classes;
char s[N], t[N];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    gets(s);
    gets(t);

    t += '$';
    n = strlen(t);

    for(int i = 0; i < n; i++)
        cnt[t[i]]++;

    for(int i = 1; i <= 'z'; i++)
        cnt[i] += cnt[i - 1];
    
    for(int i = n - 1; i >= 0; i--) {
        p[--cnt[t[i]]] = i;
    }
   
    for(int i = 1; i < n; i++) {
        if(t[p[i]] != t[p[i - 1]]) classes++;
        c[p[i]] = classes;
    }

    for(int h = 0; (1 << h) <= n; h++) {
    
        for(int i = 0; i < n; i++) {
            int pos = p[i] - (1 << h);
            if(pos < 0) pos += n;
            pn[i] = pos;
        }

        memset(cnt, 0, n * sizeof(int));

        for(int i = 0; i < n; i++) { 
            cnt[c[pn[i]]]++;
        }

        for(int i = 1; i <= n; i++) {
            cnt[i] += cnt[i - 1];
        }
       
        for(int i = n - 1; i >= 0; i--) {
            p[--cnt[c[pn[i]]]] = pn[i];
        }

        int classes = 0;
        cn[0] = 0;
        for(int i = 1; i < n; i++) {
            int mid1 = (p[i] + (1 << h)) % n, mid2 = (p[i - 1] + (1 << h)) % n;
            if(c[p[i]] != c[p[i - 1]] || c[mid1] != c[mid2]) classes++;
            cn[p[i]] = classes;
        }
        memcpy(c, cn, n * sizeof(int));
    }

    for(int i = 0; i < n; i++)
        cout << p[i] << " ";
    return 0;
}
