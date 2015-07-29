/****************************************
**      Solution by NU: Black Kex      **
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

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, ans;
char s[50], t[50];
map <string, int> dist;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d\n", &n);

    dist["polycarp"] = 1;

    for (int i = 0; i < n; i++) {
        scanf("%s reposted %s\n", s, t);
        
        for (int j = 0; s[j]; j++) {
            s[j] = tolower(s[j]);
        }

        for (int j = 0; t[j]; j++) {
            t[j] = tolower(t[j]);
        }
        
        dist[string(s)] = dist[string(t)] + 1;
        ans = max(ans, dist[string(s)]);
    }

    printf("%d\n", ans);
    
    return 0;
}
