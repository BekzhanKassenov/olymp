/*****************************************
**     Solution by Bekzhan Kassenov     **
*****************************************/

#include <bits/stdc++.h>

using namespace std;

#define by(T, x) [](const T& a, const T& b) { return a.x < b.x; }
#define all(x) (x).begin(), (x).end()

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

const double EPS = 1e-9;
const int MOD = 998244353;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct num {
    int val;

    num() : val(0) {}

    num(int n) : val(n % MOD) {}

    num& operator += (const num& other) {
        val = (val + other.val) % MOD;
        return *this;
    }

    num operator + (num other) const {
        other += *this;
        return other;
    }

    num& operator *= (const num& other) {
        long long res = val;
        res *= other.val;
        res %= MOD;
        val = res;
        return *this;
    }

    num operator * (num other) const {
        other *= *this;
        return other;
    }
};

ostream& operator << (ostream& out, const num& n) {
    out << n.val;
    return out;
}

struct Dp {
    num dp[210];
    num sum[210];
    num pref[210];
    num total;

    Dp() {
        clear();
    }

    void calc() {
        num cur = 0;
        for (int i = 200; i >= 1; i--) {
            pref[i] = pref[i + 1] + dp[i];
            sum[i] = sum[i + 1] + pref[i];
        }
        total = pref[1];
    }

    void clear() {
        total = 0;
        for (int i = 0; i < 210; i++) {
            dp[i] = 0;
            sum[i] = 0;
            pref[i] = 0;
        }
    }
};


int n;
int a[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    cin >> n;
    for (int i = 2; i <= n + 1; i++) {
        cin >> a[i];
    }

    if (n == 2) {
        if (a[2] == -1 && a[3] == -1) {
            cout << 200 << endl;
        } else if (a[2] != a[3] && a[2] != -1 && a[3] != -1) {
            cout << 0 << endl;
        } else {
            cout << 1 << endl;
        }
        return 0;
    }

    Dp *dp = new Dp(), *pr = new Dp(), *ppr = new Dp();

    a[0] = 1;
    a[1] = 1;
    a[n + 2] = 1;
    a[n + 3] = 1;
    a[n + 4] = 1;
    
    pr->dp[1] = 1;
    pr->calc();
    
    dp->dp[1] = 1;
    dp->calc();

    for (int i = 3; i <= n + 4; i++) {
        ppr->clear();
        swap(ppr, pr);
        swap(dp, pr);

        for (int k = 1; k <= 200; k++) {
            if (a[i - 1] == -1) {
                if (a[i] == -1 || a[i] == k) {
                    dp->dp[k] += ppr->total * k;
                    dp->dp[k] += ppr->sum[k + 1];
                }
            } else {
                if (k >= a[i - 1]) {
                    dp->dp[k] = ppr->total;
                } else {
                    dp->dp[k] = ppr->pref[a[i - 1]];
                }
            }
        }

        cout << dp->dp[1].val << ' ' << dp->dp[2].val << endl;
        dp->calc();

        for (int j = 1; j <= 10; j++) {
            cout << dp->pref[j] << ' ';
        }
        cout << endl;
    }

    cout << dp->total.val << endl;

    return 0;
}
