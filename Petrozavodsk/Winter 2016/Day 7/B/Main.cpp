/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

#ifdef Local
# define I64 "%I64d"
#else
# define I64 "%Ld"
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 2010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
char buf[MAXN];
bitset <MAXN> g[MAXN];
bitset <MAXN> used;
bitset <MAXN> temp;
int dist[MAXN];

long long bfs(int S) {
    for (int i = 0; i < n; i++) {
        dist[i] = n;
    }

    dist[S] = 0;
    used.set();
    used.reset(S);

    queue <int> q;
    q.push(S);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        temp = used & g[v];

        for (int i = temp._Find_first(); i < n; i = temp._Find_next(i)) {
            q.push(i);
            dist[i] = dist[v] + 1;
            used.flip(i);
        }
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += sqr(dist[i]);
    }
    
    return ans;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d\n", &n);

    for (int i = 0; i < n; i++) {
        gets(buf);

        for (int j = 0; j < n; j++) {
            if (buf[j] == '1') {
                g[i].set(j);
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += bfs(i);
    }

    printf(I64 "\n", ans);
    
    return 0;
}
