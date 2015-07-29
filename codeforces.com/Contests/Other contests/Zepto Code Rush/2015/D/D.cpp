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
const int MAXN = 1000010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

char s[MAXN];
int n, k;
int z[MAXN];
char result[MAXN];
int delta[MAXN];

void calc_z_function() {
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        
        if (i + z[i] - 1 > r)
            l = i,  r = i + z[i] - 1;
    }
}

bool is_periodic(int len, int num) {
    return len + z[len] >= len * num;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d %d\n", &n, &k);
    gets(s);
    
    calc_z_function();
    
    /*
    for (int i = 0; i < n; i++) {
        cout << setw(2) << s[i] << ' ';
    }
    cout << endl;
    
    for (int i = 0; i < n; i++) {
        cout << setw(2) << z[i] << ' ';
    }
    cout << endl;
    */
    
    for (int len = 1; len < n; len++) {
        if (1ll * len * k <= n && is_periodic(len, k)) {
            int cnt = min(z[len * k], len);
            
            //cout << len << ' ' << len * k << ' ' << cnt << endl;
            delta[len * k - 1] += 1;
            delta[len * k + cnt] += -1;           
        }
    }
    
    int cur = 0;
    for (int i = 0; i < n; i++) {
        cur += delta[i];
        if (cur > 0) {
            result[i] = '1';
        } else {
            result[i] = '0';
        }
        
        
        if ((i + 1) % k == 0 && is_periodic((i + 1) / k, k) || 
            (i + 1) % (k + 1) == 0 && is_periodic((i + 1) / (k + 1), k + 1)) {
            result[i] = '1';
        }
    }
    
    puts(result);
    return 0;
}
