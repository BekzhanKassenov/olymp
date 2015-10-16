/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define prev hggfdfch
#define next asdasd

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

long long n, t, a[10010];
pair<long long, long long> dp[2][10010];
int next = 1;
int prev = 0;

pair<long long, long long> recalc(pair<long long, long long> m, long long value) {
    long long f = m.first, s = m.second;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    cin >> t >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dp[0][i] = MP(1, a[i] % t);
    }
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            long long f = dp[prev][j].first,
                s = dp[prev][j].second;

            pair<long long, long long> mp1 = MP(f + ((s + a[j + i]) >= t ? 1 : 0), s + a[j + i] <= t ? ((s + a[j + i])%t) : a[j + i]);
            f = dp[prev][j + 1].first;
            s = dp[prev][j + 1].second;
            pair<long long, long long> mp2 = MP(f + ((s + a[j]) >= t ? 1 : 0), s + a[j] <= t ? ((s + a[j])%t) : a[j]);
            if (mp1.first < mp2.first) {
                dp[next][j] = mp1;
            }
            else if (mp1.first > mp2.first) {
                dp[next][j] = mp2;
            }
            else if (mp1.second < mp2.second)  {
                dp[next][j] = mp1;
            }
            else {
                dp[next][j] = mp2;
            }
 
        }
        swap(next, prev);
    }

    cout << dp[prev][0].first;
    return 0;
}
