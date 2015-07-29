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
const int MOD = 1000 * 1000 * 1000 + 9;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 400010;
const int BASE = 23;
const int MAGIC = 7;
                     
template <typename T>
inline T sqr(T n) {
    return n * n;
}

int hash[MAGIC * MAXN], power[MAGIC * MAXN];
char s[MAGIC * MAXN], temp[MAXN];
int k, n, ansl = -1, ansr = -1, power10 = 1, cur;
int last[MAXN];

bool cmp(int L, int R, int LL, int RR) {
    if (R - L != RR - LL)
        return R - L < RR - LL;

    int diff = power[abs(L - LL)];

    int prevL = 0;
    if (L > 0)
        prevL = hash[L - 1];

    int prevLL = 0;
    if (LL > 0)
        prevLL = hash[LL - 1];

    int left = 0, right = R - L;
    while (left < right) {
        int mid = (left + right) / 2;

        int hashL = (hash[L + mid] - prevL + MOD) % MOD;
        int hashLL = (hash[LL + mid] - prevLL + MOD) % MOD;

        if (L < LL)
            hashL = (hashL * 1ll * diff) % MOD;
        else
            hashLL = (hashLL * 1ll * diff) % MOD;

        if (hashL == hashLL)
            left = mid + 1;
        else
            right = mid;
    }
    
    return left < R - L && s[L + left] < s[LL + left];
}

int stupid() {
    int ans = 100;

    for (int i = 0; i < n; i++) {
        int num = 0;
        for (int j = 0; j < 2 && i + j < n; j++) {
            num = num * 10 + s[i + j] - '0';
            if (num % k == 0)
                ans = min(ans, num);
        }
    }

    if (ans == 100)
        return -1;

    return ans;
}

void init() {
    int prn = strlen(temp);

    for (int i = 0; i < MAGIC && n + prn < MAGIC * MAXN; i++) {
        strcat(s, temp);
        n += prn;
    }

    hash[0] = s[0];
    power[0] = 1;

    for (int i = 1; i < n; i++) {
        power[i] = (power[i - 1] * 1ll * BASE) % MOD;
        hash[i] = (hash[i - 1] + s[i] * 1ll * power[i]) % MOD;
    }
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    gets(temp);
    scanf("%d", &k);

    init();

    if (k == 2 || k == 5) {
        printf("%d\n", stupid());
        return 0;
    }

    memset(last, 255, sizeof last);
    last[0] = n;

    for (int i = n - 1; i >= 0; i--) {
        cur = (cur + (s[i] - '0') * 1ll * power10) % k;
        power10 = (power10 * 10) % k;

        if (last[cur] != -1 && (ansl == -1 || cmp(i, last[cur], ansl, ansr)))
            ansl = i, ansr = last[cur];

        last[cur] = i;
    }

    if (ansl == -1)
        puts("-1");
    else {
        for (int i = ansl; i < ansr; i++)
            putchar(s[i]);
        
        puts("");
    }

    return 0;
}
