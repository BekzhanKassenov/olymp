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
const int maxn = 2010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

pair <int, int> a[2][maxn];
int size[2], ptr[2], n, t, x, h, m;

int make(int num, int cur) {
    priority_queue <int> q[2];

    ptr[0] = ptr[1] = 0;
    int ans = 0;

    do {
        while (ptr[0] < size[0] && a[0][ptr[0]].F <= cur) {
            q[0].push(a[0][ptr[0]++].S);
        }

        while (ptr[1] < size[1] && a[1][ptr[1]].F <= cur) { 
            q[1].push(a[1][ptr[1]++].S);
        }

        if (q[num].empty())
            return ans;

        cur += q[num].top();
        q[num].pop();
        ans++;

       num ^= 1;
    } while (true); 

    return ans; 
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &x);

    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &t, &h, &m);

        a[t][size[t]++] = MP(h, m);
    }

    sort(a[0], a[0] + size[0]);
    sort(a[1], a[1] + size[1]);

    printf("%d\n", max(make(0, x), make(1, x)));
    
    return 0;
}
