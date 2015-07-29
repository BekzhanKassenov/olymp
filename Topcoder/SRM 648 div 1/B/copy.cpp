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

long long power(long long base, long long p) {
    long long result = 1;
    
    while (p) {
        if (p & 1) {
            result *= base;
        }

        base *= base;
        p >>= 1;
    }

    return result;
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

struct Number {
    int power;
    int base;

    Number() { }

    Number(int power, int base) : power(power), base(base) { }

    bool operator < (const Number& numb) const {
        int powerthis = power;
        int powernumb = numb.power;

        int powermin = min(powerthis, powernumb);
        powerthis -= powermin;
        powernumb -= powermin;

        long long lhs = base;
        lhs *= power(2, powerthis);

        long long rhs = numb.base;
        rhs *= power(2, powernumb);

        return lhs < rhs;
    }
};

class KitayutaMart {
public:
    int lastPrice(int N, int K) {
        Number lastOdd(1, 0);

        set <pair <Number, int> > Set;
        Set.insert(make_pair(lastOdd, 1));

        int curcnt = 0;
        int ans = 0;

        while (curcnt < N) {
            int cnt = Set.begin()->second;
            int toAdd = cnt;
            Number cur = Set.begin()->first;

            if (!(cur < lastOdd) && lastOdd.base < K) {
                cur = lastOdd;
                cnt = 1;
                lastOdd.base += 2;
            } else {
                Set.erase(Set.begin());
            }

            if (curcnt + toAdd >= N) {
                toAdd = K - curcnt;
            }

            curcnt += toAdd;
            toAdd = ((1ll * toAdd * powmod(2, cur.power)) % MOD) * 1ll * cur.base % MOD;
            ans = (ans + toAdd) % MOD;
            cnt++;
            cur.power++;

            Set.insert(make_pair(cur, cnt));
        }

        return ans;
    }
};

int main() {
    KitayutaMart a;
    
    cout << a.lastPrice(5, 8) << endl;
    cout << a.lastPrice(3, 1) << endl;
    
    return 0;
}
