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

int m;
vector <int> ans;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &m);

    int cnt = 0;

    for (int i = 1; ; i++) {
        int temp = i;

        while (temp % 5 == 0) {
            cnt++;
            temp /= 5;
        }

        if (cnt == m) {
            ans.push_back(i);
        } else if (cnt > m) {
            break;
        }
    }

    printf("%llu\n", ans.size());
    for (int x: ans) {
        printf("%d ", x);
    }

    return 0;
}
