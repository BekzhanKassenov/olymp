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

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, p;
char s[MAXN], t[MAXN];
int ans;
int minl = MAXN + 1, maxl = 0;
int minr = MAXN + 1, maxr = 0;

int dist(char a, char b) {
    int ans = abs(a - b);
    ans = min(ans, min(a, b) - 'a' + 'z' - max(a, b) + 1);
    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d %d\n", &n, &p);
    
    gets(s);
    strcpy(t, s);
    
    p--;
    

    for (int i = 0; i < n / 2; i++) {
        ans += dist(s[i], s[n - i - 1]);
        if (s[i] != s[n - i - 1]) {
            minl = min(minl, i);
            maxl = max(maxl, i);

            minr = min(minr, n - i - 1);
            maxr = max(maxr, n - i - 1);
        }
    }

    if (ans == 0) {
        puts("0");
        return 0;
    } 
    
    int ansl = maxl - minl + min(abs(p - minl), abs(p - maxl));
    int ansr = maxr - minr + min(abs(p - minr), abs(p - maxr)); 
    ans += min(ansl, ansr);

    printf("%d", ans);

    return 0;
}
