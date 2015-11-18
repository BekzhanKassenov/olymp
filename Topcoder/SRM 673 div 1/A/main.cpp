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

template <typename T>
inline T sqr(T n) {
    return n * n;
}

class BearCavalry{
    int fact(int n) {
        if (n == 0) {
            return 1;
        }

        return (1ll * fact(n - 1) * n) % MOD;
    }
    
    int solve(vector <int> w, vector <int> h, int C) {
        vector <vector <int> > limit(w.size());

        for (size_t i = 0; i < h.size(); i++) {
            int lim = (C + h[i] - 1) / h[i];

            bool inserted = false;
            for (int j = w.size() - 1; j >= 0; j--) {
                if (w[j] < lim) {
                    limit[j].push_back(i);
                    inserted = true;
                    break;
                }
            }

            if (!inserted) {
                return 0;
            }
        }

        int ans = 1;
        int cnt = 0;
        for (size_t i = 0; i < w.size(); i++) {
            cnt += limit[i].size();

            if (cnt > (int)i + 1) {
                return 0;
            }

            ans = (1ll * ans * fact(limit[i].size())) % MOD;
        }

        return ans;
    }

public:
    int countAssignments(vector <int> w, vector <int> h) {
        int ans = 0;

        int ww = w[0];
        w.erase(w.begin());

        for (size_t i = 0; i < h.size(); i++) {
            int hh = h[i];
            h.erase(h.begin() + i);
            ans += solve(w, h, ww * hh);
            ans %= MOD;

            h.insert(h.begin() + i, hh);
        }   

        return ans;
    }
};