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

int code(char c) {
    if (islower(c)) {
        return c - 'a';
    }

    return c - 'A' + 26;
}

int n;
char s[MAXN];
int cnt[MAXN][52];
bool has[52];

bool check(int l, int r) {
    for (int i = 0; i < 52; i++) {
        if (has[i] && cnt[r][i] - cnt[l - 1][i] == 0) {
            return false;
        }
    }
    
    return true;
}

int bin_search(int start) {
    int l = start, r = n;
    int ans = n;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(start, mid)) {
            ans = min(ans, mid - start + 1);
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    
    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d\n", &n);
    gets(s + 1);
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 52; j++) {
            cnt[i][j] = cnt[i - 1][j];
        }
        
        cnt[i][code(s[i])]++;
        has[code(s[i])] = true;
    }
    
    int ans = n;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, bin_search(i));
    }
    
    printf("%d\n", ans);

    return 0;
}