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

vector <int> ans;

bool prime(int n) {
    if (n % 2 == 0) {
        return n == 2;
    }

    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int n;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 2; i <= n; i++) {
        if (prime(i)) {
            int cur = i;

            while (cur <= n) {
                ans.push_back(cur);
                cur *= i;
            }
        }
    }

    printf("%u\n", ans.size());

    for (int q: ans) {
        printf("%d ", q);
    }

    puts("");

    return 0;
}
