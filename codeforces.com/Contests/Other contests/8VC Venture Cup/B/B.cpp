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
const int N = 60;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

long long a, b;
int s[N], x[N];

void convert(long long n, int arr[N]) {
    for (int i = 0; i < N; i++) {
        arr[i] = n & 1;
        n >>= 1;
    }
}

bool calced[N][2];
long long dp[N][2];

long long go(int pos, int carry) {
    if (calced[pos][carry]) {
        return dp[pos][carry];
    }

    calced[pos][carry] = true;
    long long& ans = dp[pos][carry];

    ans = 0;

    if (pos == N - 1) {
        ans = carry == 0;
        return ans;
    }

    for (int ba = 0; ba < 2; ba++) {
        for (int bb = 0; bb < 2; bb++) {
            if ((ba + bb + carry) % 2 == s[pos] && (ba ^ bb) == x[pos]) {
                ans += go(pos + 1, (ba + bb + carry) / 2);
            }
        }
    }

    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%lld%lld", &a, &b);

    convert(a, s);
    convert(b, x);

    long long ans = go(0, 0);
    if (a == b) {
        ans -= 2;
    }

    printf("%lld\n", ans);

    return 0;
}
