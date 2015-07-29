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

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

const int maxn = 110;

int n, s[maxn], cards[maxn][maxn], ciel, jiro, l, r;
vector <int> remain;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &s[i]);
        
        for (int j = 0; j < s[i]; j++)
            scanf("%d", &cards[i][j]);
    }
    
    for (int i = 0; i < n; i++) {
        l = 0, r = s[i] - 1;
        
        while (l < r) {
            ciel += cards[i][l];
            jiro += cards[i][r];
            l++;
            r--;
        }
        
        if (l == r)
            remain.push_back(cards[i][l]);
    }
    
    sort(all(remain));
    reverse(all(remain));
    
    for (size_t i = 0; i < remain.size(); i++) {
        if (i & 1)
            jiro += remain[i];
        else
            ciel += remain[i];
    }
    
    printf("%d %d\n", ciel, jiro);
    
    return 0;
}   
