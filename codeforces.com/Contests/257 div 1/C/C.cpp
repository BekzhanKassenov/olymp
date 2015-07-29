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

int n;
bool used[maxn];
pair <int, int> ans[maxn];
int last;

void push(int p, int val) {
    if (used[val])
        return;

    if (p == -1)
        p = val;
    else {
        used[p] = true;
        used[val] = true;
        ans[last++] = MP(p, val);
        p = -1;
    }

    p = -1;
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    
    scanf("%d", &n);

    int p;

    for (int i = 2; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            push(p, j);
        }

        p = -1;
    }

    printf("%d\n", last);

    for (int i = 0; i < last; i++)
        printf("%d %d\n", ans[i].F, ans[i].S);

    return 0;
}
