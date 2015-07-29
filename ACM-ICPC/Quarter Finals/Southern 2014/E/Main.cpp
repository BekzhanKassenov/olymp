/****************************************
**          Solution by NU #2          **
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
const int MAXN = 200010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

vector <int> g[MAXN];
int n;
int m[MAXN], r[MAXN];
int used[MAXN], timer;
int mt[MAXN];
int good, bad;
vector <pair <int, int> > ans;

bool win(int i) {
    return m[i] > r[i];
}

bool kuhn(int v) {
    if (used[v] == timer)
        return false;

    used[v] = timer;

    for (size_t i = 0; i < g[v].size(); i++) {
        int to = g[v][i];

        if (mt[to] == -1 || kuhn(mt[to])) {
            mt[to] = v;
            return true;
        }
    }

    return false;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &m[i], &r[i]);
        
        if (m[i] > r[i])
            good++;
        else
            bad++;
    }

    if (good > bad) {
        puts("0");
        return 0;
    }

    for (int i = 1; i < n; i++) {
        if ((win(i) ^ win(i + 1)) && m[i] + m[i + 1] > r[i] + r[i + 1]) {
            g[i].push_back(i + 1);
            g[i + 1].push_back(i);
            continue;
        }

        if (!win(i) && !win(i + 1)) {
            g[i].push_back(i + 1);
            g[i + 1].push_back(i);
            continue;
        }
    }

    memset(mt, 255, sizeof mt);

    for (int i = 1; i <= n; i += 2) {
        timer++;
        kuhn(i);
    }

    for (int i = 1; i <= n && good <= bad; i++) {
        if (mt[i] != -1) {
            bad--;
            ans.push_back(make_pair(mt[i], i));
        }
    }

    if (good > bad) {
        printf("%d\n", ans.size());

        for (size_t i = 0; i < ans.size(); i++)
            printf("%d %d\n", ans[i].first, ans[i].second);
    } else {
        puts("-1");
    }
    
    return 0;
}
