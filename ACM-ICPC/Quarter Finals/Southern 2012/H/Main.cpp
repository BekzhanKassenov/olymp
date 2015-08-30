/****************************************
**          Solution by NU #2          **
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

long long n, m, k;
long long w[MAXN], c[MAXN];
long long sumW[MAXN], sumC[MAXN];
long long ans, ansl, ansr;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    scanf("%I64d%I64d%I64d", &n, &m, &k);

    for (int i = 1; i <= n; i++) {
        scanf("%I64d%I64d", &w[i], &c[i]);

        sumW[i] = sumW[i - 1] + w[i];
        sumC[i] = sumC[i - 1] + c[i];
    }

    long long costH = 0;
    for (int i = n; i - m > 0; i--) {
        long long sum = sumW[i] - sumW[i - m];

        if (sum > k * sumW[i - m]) {
            break;
        }

        int _left = 1, _right = i - m;
        int _res = -1;

        while (_left <= _right) {
            int _mid = (_left + _right) / 2;

            long long _lhs = (sumW[i - m] - sumW[_mid]) * k;

            if (_lhs >= sum) {
                _res = _mid;
                _left = _mid + 1;
            } else {
                _right = _mid - 1;
            }
        }

        if (_res != -1) {
            if (ans < costH + sumC[_res]) {
                ans = costH + sumC[_res];
                ansr = n - i;
                ansl = _res;
            }
        } else {
            long long _lhs = sumW[i - m] * k;

            if (_lhs >= sum) {
                if (ans < costH) {
                    ans = costH;
                    ansr = n - i;
                    ansl = 0;
                }
            }
        }

        costH += c[i];
    }

    printf("%I64d %I64d\n", ansl + ansr, ans);
    for (int i = 0; i < ansr; i++) {
        putchar('H');
    }

    for (int i = 0; i < ansl; i++) {
        putchar('T');
    }

    putchar('\n');

    return 0;
}
