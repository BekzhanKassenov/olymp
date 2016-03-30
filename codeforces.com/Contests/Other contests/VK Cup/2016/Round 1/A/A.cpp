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
const int MAXN = 150010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, q, k;
int t[MAXN];
vector <int> cur;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d%d", &n, &k, &q);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &t[i]);
    }

    while (q--) {
        int type, id;
        scanf("%d%d", &type, &id);

        if (type == 1) {
            if ((int)cur.size() < k) {
                cur.push_back(id);
            } else {
                int mn = 0;
                for (int i = 1; i < k; i++) {
                    if (t[cur[i]] < t[cur[mn]]) {
                        mn = i;
                    }
                }

                if (t[cur[mn]] < t[id]) {
                    cur[mn] = id;
                }
            }
        } else {
            bool flag = false;
            for (int x: cur) {
                if (x == id) {
                    flag = true;
                }
            }

            if (flag) {
                puts("YES");
            } else {
                puts("NO");
            }
        }
    }

    return 0;
}
