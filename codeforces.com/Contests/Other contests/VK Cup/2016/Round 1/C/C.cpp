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
const int MAXN = 200010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, k;
int a[MAXN];
int sum[2 * MAXN];

int ss[2 * MAXN];

int sign(int n) {
    return (n > 0) - (n < 0);
}

bool compare(int a[], int lena, int b[], int lenb) {
    if (lena != lenb) {
        return lena < lenb;
    }

    for (int i = 0; i < lena; i++) {
        if (a[i] != b[i]) {
            return a[i] < b[i];
        }
    }

    return true;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &k);

    for (int i = 0; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    int mxpos = 0;

    for (int i = 0; i <= n; i++) {
        int s = sign(a[i]);
        int t = abs(a[i]);
        int pos = i;

        while (t > 0) {
            sum[pos++] += (t % 2) * s;
            mxpos = max(mxpos, pos);
            t /= 2;
        }
    }

    long long carry = 0;
    for (int i = 0; i < mxpos || carry; i++) {
        carry += sum[i];

        if (carry > 0) {
            sum[i] = carry & 1;
            carry >>= 1;
        } else {
            if (abs(carry) % 2 == 1) {
                sum[i] = 1;
                carry = -((-carry) / 2 + 1);
            } else {
                sum[i] = 0;
                carry /= 2;
            }
        }

        if (i >= mxpos && carry == -1 && sum[i] == 1) {
            sum[i] = -1;
            carry = 0;
            mxpos = i + 1;
            break;
        }
    }

    sum[mxpos - 1] = 1;

    int cnt = 0;
    for (int i = 0; i < mxpos; i++) {
        if (sum[i] != 0) {
            break;
        }

        cnt++;
    }

    for (int i = 0; i <= mxpos - cnt; i++) {
        sum[i] = sum[i + cnt];
    }
    mxpos -= cnt;

    for (int i = 0; i < mxpos; i++) {
        cerr << sum[i];
    }
    cerr << endl;

    int ans = 0;
    for (int i = 0; i < cnt; i++) {
        long long t = abs(k + a[i]);

        int last = 0;
        while (t > 0) {
            ss[last++] = t & 1;
            t >>= 1; 
        }

        if (compare(sum, mxpos, ss, last)) {
            ans++;
        }
    }

    printf("%d\n", ans);

    return 0;
}
