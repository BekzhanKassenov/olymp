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
const int maxn = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, x, y;
map <int, vector <int> > Map;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &x, &y);

        vector <int> temp;

        for (int d = 1; d * d <= x; d++) {
            if (x % d == 0) {
                temp.push_back(d);

                if (d * d != x)
                    temp.push_back(x / d);
            }
        }

        int ans = 0;

        for (size_t j = 0; j < temp.size(); j++) {
            vector <int> :: iterator it = lower_bound(all(Map[temp[j]]), i - y);

            if (it == Map[temp[j]].end())
                ans++;
        } 

        for (size_t j = 0; j < temp.size(); j++)
            Map[temp[j]].push_back(i);

        printf("%d\n", ans);
    }

    return 0;
}
