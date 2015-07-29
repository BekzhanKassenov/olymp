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

int n;
char s[2 * MAXN];
int cnt[26];
int ans;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d\n", &n);
    gets(s);

    int pos = 0;
    for (int i = 0; i < n - 1; i++) {
        cnt[s[pos] - 'a']++;

        pos++;

        if (cnt[s[pos] - 'A'] > 0) {
            cnt[s[pos] - 'A']--;
        } else {
            ans++;
        }

        pos++;
    }

    printf("%d\n", ans);
    
    return 0;
}
