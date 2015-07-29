/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);
const int maxn = 1010;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

struct item {
    int cost, size;
    int num;

    void read() {
        scanf("%d%d", &size, &cost);
    }

    bool operator < (const item& it) const {
        if (cost != it.cost)
            return cost > it.cost;

        return size < it.size;
    }
};

int n, m, r[maxn], sum;
item a[maxn];
bool used[maxn];
vector <PII> ans;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        a[i].read();
        a[i].num = i + 1;
    }

    sort(a, a + n);

    scanf("%d", &m);

    for (int i = 0; i < m; i++)
        scanf("%d", &r[i]);

    for (int i = 0; i < n; i++) {
        int pos = -1;

        for (int j = 0; j < m; j++) {
            if (!used[j] && r[j] >= a[i].size) {
                if (pos == -1 || r[j] < r[pos])
                    pos = j;
            }
        }

        if (pos != -1) {
            ans.push_back(MP(a[i].num, pos + 1));
            used[pos] = true;
            sum += a[i].cost;
        }
    }

    printf("%u %d\n", ans.size(), sum);

    for (size_t i = 0; i < ans.size(); i++)
        printf("%d %d\n", ans[i].F, ans[i].S);

    return 0;
}
