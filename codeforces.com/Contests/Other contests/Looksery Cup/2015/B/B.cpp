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
const int MAXN = 110;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

vector <int> ans;
int deg[MAXN], cnt[MAXN], a[MAXN];
char s[MAXN][MAXN];
int n;
set <int> Set;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d\n", &n);

    for (int i = 0; i < n; i++) {
        gets(s[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] == 0) {
            Set.insert(i);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] == '1') {
                deg[i]++;
            }
        }
    }

    while (!Set.empty()) {
        int v = *Set.begin();
        Set.erase(Set.begin());
        ans.push_back(v + 1);

        for (int i = 0; i < n; i++) {
            if (s[v][i] == '1') {
                cnt[i]++;

                if (Set.count(i)) {
                    Set.erase(i);
                } else {
                    if (cnt[i] == a[i]) {
                        Set.insert(i);
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (cnt[i] == a[i]) {
            puts("-1");
            return 0;
        }
    }

    printf("%u\n", ans.size());

    for (size_t i = 0; i < ans.size(); i++) {
        printf("%d ", ans[i]);
    }

    return 0;
}
