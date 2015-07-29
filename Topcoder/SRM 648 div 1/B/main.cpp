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

int powmod(int base, int p) {
    int result = 1;

    while (p) {
        if (p & 1) {
            result = (1ll * result * base) % MOD;
        }

        base = (1ll * base * base) % MOD;
        p >>= 1;
    }

    return result;
}

class KitayutaMart {
public:
    int lastPrice(int N, int K) {
        int curcnt = 0;
        int ans = 0;

        for (int i = 1; i <= K && curcnt < N; i++) {
            int cnt = __builtin_ctz(i);
            curcnt += (cnt * (cnt + 1)) / 2 + 1;
            ans = i;
        }

        if (!(curcnt < N)) {
            return ans;
        }
        
        int rem = N % curcnt;
        int bnum = (N + curcnt - 1) / curcnt;

        int temp = 0;
        for (int i = 1; i <= K; i++) {
            int cnt = __builtin_ctz(i);
            temp += (cnt * (cnt + 1)) / 2 + 1;
            ans = i;

            if (temp >= rem) {
                break;
            }
        }

        ans = (1ll * ans * powmod(2, bnum)) % MOD;

        return ans;
    }
};

int main() {
    KitayutaMart a;
    
    cout << a.lastPrice(5, 3) << endl;
    
    return 0;
}
