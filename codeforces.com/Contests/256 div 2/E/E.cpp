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
const int lim = 100000;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

ll x, k;
int nb;
vector <ll> ans;
vector <ll> divs;
bool flag;

bool prime(ll x) {
    for (size_t i = 1; i < divs.size() && divs[i] * divs[i] <= x; i++) {
        if (x % divs[i] == 0 && x != divs[i]) {
            return false;
        }
    }
    return true;
}

bool add_ans(ll num) {
    if ((int)ans.size() < lim) {
        ans.push_back(num);
        return true;
    }
    return false;
}

void solve(ll x, ll k) {
    if (k == 0) {
        add_ans(x);
        return;
    }
    if (x == 1) {
        add_ans(1);
        return;
    }
    if (prime(x)) {
        for (ll i = 0; i < k && (int)ans.size() < lim; i++) {
            if (!add_ans(1)) {
                break;
            }
        }
        add_ans(x);
        return;
    }
    for (size_t i = 0; i < divs.size() && divs[i] <= x && (int)ans.size() < lim; i++) {
        if (x % divs[i] == 0) {
            solve(divs[i], k - 1);
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    scanf("%lld %lld", &x, &k);

    if (x == 1) {
        puts("1");
        return 0;
    }

    if (k > lim) {
        for (int i = 0; i < lim; i++) {
            printf("1 ");
        }

        puts("");
        return 0;
    }

    if (k == 0) {
        printf("%lld\n", x);
        return 0;
    }

    for (ll i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            divs.push_back(i);
            if (i * i != x) {
                divs.push_back(x / i);
            }
        }
    }

    sort(all(divs));
    solve(x, k);

    for (size_t i = 0; i < ans.size(); i++) {
        printf("%lld ", ans[i]);
    }
    puts("");

    return 0;
}
