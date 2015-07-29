#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <utility>
#include <cassert>

#define fname ""
#define F first
#define S second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long LL;
typedef pair <int, int> PII;
typedef vector <int> VI;

const int maxn = 1000 * 1000;
const int inf = 2 * 1000 * 1000 * 1000;
const int mod = 1000 * 1000 * 1000 + 7;
const int MAX_N = 1000 * 10000;

char s[maxn], ans;
int d, n, R[20], T, h, lh, pos[maxn];

bool check(int l1, int r1, int l2, int r2) {
    int k1 = l1 % n, k2 = l2 % n;

    for (int i = 0; i < min(10, r1 - l1 + 1); ++i) {
        if (s[k1] > s[k2])
            return true;
        if (s[k1] < s[k2])
            return false;
        k1++;
        k2++;
        if (k1 == n)
            k1 = 0;
        if (k2 == n)
            k2 = 0;
    }

    return false;
}

int main() {
    freopen("in", "r", stdin);
//  freopen(fname"out", "w", stdout);

    scanf("%s", s);
    scanf("%d", &d);

    n = strlen(s);

    if (d == 2 || d == 5) {
        ans = '9';
        for (int i = 0; i < n; ++i)
            if ((s[i] - '0') % d == 0)
                ans = min(ans, s[i]);

        if (ans == '9')
            puts("-1");
        else
            printf("%c\n", ans);
        
        return 0;
    }

    R[1] = 1;
    for (int i = 2; i < min(11,d); ++i)
        R[i] = (d - ((d / i) * 1ll * R[d % i] % d)) % d;
    
    T = 1;
    h = s[0] - '0';

    for (int i = 0; i < d; ++i)
        pos[i] = -1;

    int k = 0, l = -1, r = inf;

    R[10] = R[10 % d];

    for (int i = 0; i < MAX_N; ++i) {
        lh = (h * 1ll * T) % d;
        if (pos[lh] != -1 && (r - l > i - pos[lh] - 1 || (r - l == i - pos[lh] - 1 && check(l, r, pos[lh] + 1, i)))) {
            l = pos[lh] + 1;
            r = i;
        }
        pos[lh] = i;
        if (++k == n)
            k = 0;
        h = (h * 10ll % d + s[k] - '0') % d;
        T = (T * 1ll * R[10]) % d;
    }

    if (r == inf) {
        puts("-1");
        return 0;
    }

    k = l % n;

    for (int i = 0; i < r - l + 1; ++i) {
        printf("%c", s[k]);
        if (++k == n)
            k = 0;
    }
    return 0;
}