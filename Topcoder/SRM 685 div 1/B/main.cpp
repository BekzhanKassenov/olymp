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
const int MAXN = 10;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

bool dp[1 << MAXN];
bool calced[1 << MAXN];

class FoxAirline2 {
    vector <int> g[MAXN];
    int n;

    bool go(int mask) {
        if (__builtin_popcount(mask) == 1) {
            return true;
        }

        if (calced[mask]) {
            return dp[mask];
        }

        bool& ans = dp[mask];

        for (int i = 0; i < n && !ans; i++) {
            if (mask & (1 << i)) {
                int cnt = 0;
                for (int to: g[i]) {
                    if (mask & (1 << to)) {
                        cnt++;
                    }
                }

                if (cnt > 1) {
                    ans |= mask ^ (1 << i);
                }
            }
        }

        return ans;
    }
public:
    string isPossible(int n, vector <int> a, vector <int> b) {
        this->n = n;

        int m = a.size();

        for (int i = 0; i < m; i++) {
            g[a[i]].push_back(b[i]);
            g[b[i]].push_back(a[i]);
        }

        if (go((1 << n) - 1)) {
            return "Possible";
        } else {
            return "Impossible";
        }
    }
};