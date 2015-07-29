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
const int MAXN = 4 * 100010;
const int BASE = 37;
                  
template <typename T>
inline T sqr(T n) {
    return n * n;
}

char temp[MAXN];
char s[10 * MAXN];
int n, k, last[MAXN];
int hash[10 * MAXN], power[10 * MAXN];
int MAGIC = 1;

int stupid() {
    int ans = 100;

    for (int i = 0; i < n; i++) {
        if (s[i] != '0' && (s[i] - '0') % k == 0)
            ans = min(ans, s[i] - '0');
    }

    if (ans == 100)
        return -1;

    return ans;
}

void init() {
    hash[0] = s[0] - '0' + 1;
    power[0] = 1;

    for (int i = 1; i < n; i++) {
        power[i] = (power[i - 1] * 1ll * BASE) % MOD;
        hash[i] = (hash[i - 1] + power[i] * 1ll * (s[i] - '0' + 1)) % MOD;
    }
}

bool cmp(int l1, int r1, int l2, int r2) {
    //cout << l1 << ' ' << r1 << ' ' << l2 << ' ' << r2 << endl;
    
    if (s[l1] == '0')
        return false;

    if (r1 - l1 != r2 - l2)
        return r1 - l1 < r2 - l2;
    
    int diff = power[l2 - l1];

    int prev1 = 0;
    if (l1)
        prev1 = hash[l1 - 1];

    int prev2 = 0;
    if (l2)
        prev2 = hash[l2 - 1];

    int left = -1, right = r1 - l1;
    while (right - left > 1) {
        int mid = (left + right) / 2;

        int hash1 = (hash[l1 + mid] - prev1 + MOD) % MOD;
        int hash2 = (hash[l2 + mid] - prev2 + MOD) % MOD;

        hash1 = (hash1 * 1ll * diff) % MOD;

        if (hash1 == hash2)
            left = mid;
        else
            right = mid;
    }

    int pos1 = max(l1, l1 + right - 5);
    int pos2 = max(l2, l2 + right - 5);

    for (int i = 0; i < 10 && pos1 < r1; i++, pos1++, pos2++) {
        if (s[pos1] != s[pos2])
            return s[pos1] < s[pos2];
    }

    return false;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    gets(temp);
    n = strlen(temp);

    while ((MAGIC + 1) * n < 2500000)
        MAGIC++;

    for (int i = 0; i < MAGIC * n; i++)
        s[i] = temp[i % n];

    n *= MAGIC;

    if (find(s, s + n, '0') != s + n) {
        puts("0");
        return 0;
    }
    
    scanf("%d", &k);

    if (k == 2 || k == 5) {
        printf("%d\n", stupid());
        return 0;
    }

    init();
    memset(last, 255, sizeof last);
    last[0] = n;
    int cur = 0;
    int power10 = 1;
    int ansl = -1, ansr = -1;

    for (int i = n - 1; i >= 0; i--) {
        cur = (cur + (s[i] - '0') * power10) % k;
        power10 = (power10 * 10) % k;

        //cout << ansl << ' ' << ansr << endl;

        if (s[i] != '0' && last[cur] != -1 && (ansl == -1 || cmp(i, last[cur], ansl, ansr)))
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