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
const int MAXN = 10010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;
int dist[2 * MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);
    
    memset(dist, 255, sizeof dist);
    dist[n] = 0;
    queue <int> q;
    q.push(n);

    while (!q.empty()) {
        int num = q.front();
        q.pop();

        if (num - 1 > 0 && dist[num - 1] == -1) {
            dist[num - 1] = dist[num] + 1;
            q.push(num - 1);
        }

        if (num * 2 < 2 * MAXN && dist[num * 2] == -1) {
            dist[num * 2] = dist[num] + 1;
            q.push(num * 2);
        }
    }

    printf("%d\n", dist[m]);

    return 0;
}
