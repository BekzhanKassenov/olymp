/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "arsenal"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
vector <int> pos[MAXN];

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        pos[x].push_back(i + 1);
    }

    vector <int> order;
    int ans = 0;
    for (int i = 1000; i >= 0; i--) {
        size_t idx = 0;
        while (idx < pos[i].size()) {
            size_t end = idx + 1;
            while (end < pos[i].size() && pos[i][end - 1] + 1 == pos[i][end]) {
                end++;
            }

            for (size_t j = idx + 1; j < end; j += 2) {
                ans++;
                order.push_back(pos[i][j]);
            }

            for (size_t j = idx; j < end; j += 2) {
                order.push_back(pos[i][j]);
            }

            idx = end;
        }
    }

    printf("%d\n", ans);
    for (int x : order) {
        printf("%d ", x);
    }
    puts("");

    return 0;
}
