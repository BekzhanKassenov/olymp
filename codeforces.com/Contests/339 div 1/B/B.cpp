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
long long A, cf, cm, m;
pair <long long, int> a[MAXN];
long long sum[MAXN];

bool check(long long minVal, int pos, long long S) {
    pair <long long, int>* ptr = upper_bound(a + 1, a + pos + 1, make_pair(minVal, 0), 
        [](const pair <long long, int>& a, const pair <long long, int>& b) {
            return a.first < b.first;
        }
    );

    int p = (ptr - a) - 1;

    if (p < 1) {
        return false;
    }

    return minVal * p - sum[p] <= S;
}

long long getMin(int pos, long long S) {
    long long l = a[0].first;
    long long r = A;

    long long ans = a[0].first;
    while (l <= r) {
        long long mid = (l + r) / 2;

        if (check(mid, pos, S)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%I64d%I64d%I64d%I64d", &n, &A, &cf, &cm, &m);

    long long full = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%I64d", &a[i].first);
        a[i].second = i;
        full += A - a[i].first;
    }

    if (full <= m) {
        long long ans = cf * n + cm * A;

        printf("%I64d\n", ans);
        for (int i = 1; i <= n; i++) {
            printf("%I64d ", A);
        }

        return 0;
    }

    sort(a + 1, a + 1 + n);
    
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i].first;
    }

    long long ans = 0;
    long long mn = INF;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        mn = min(mn, a[i].first);
        if (a[i].first == A) {
            cnt++;
        }
    }

    ans = cf * cnt + mn * cm;

    long long toMax = 0;
    int curMax = 0;

    int cntMax = 0;
    long long minVal = 0;
    for (int i = n; i > 0; i--) {
        if (toMax <= m) {
            long long rest = m - toMax;

            long long curMin = getMin(i, rest);

            if (ans < cf * curMax + cm * curMin) {
                ans = cf * curMax + cm * curMin;
                cntMax = curMax;
                minVal = curMin;
            }
        }

        curMax++;
        toMax += A - a[i].first;
    }

    for (int i = 1; i <= n; i++) {
        if (a[i].first <= minVal) {
            a[i].first = minVal;
        }
    }

    for (int i = n; i >= 0 && cntMax; i--) {
        a[i].first = A;
        cntMax--;
    }

    sort(a + 1, a + 1 + n, [](const pair <long long, int>& a, const pair <long long, int>& b) {
        return a.second < b.second;
    });

    printf("%I64d\n", ans);

    for (int i = 1; i <= n; i++) {
        printf("%I64d ", a[i].first);
    }

    return 0;
}
