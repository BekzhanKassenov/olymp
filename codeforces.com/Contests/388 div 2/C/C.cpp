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
const int MAXN = 200010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
char s[MAXN];
bool dead[MAXN];
queue <int> d, r, all;

int get(queue <int>& q) {
    while (!q.empty()) {
        int p = q.front();
        q.pop();
        if (!dead[p]) {
            return p;
        }
    }

    return -1;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d\n", &n);
    gets(s);

    for (int i = 0; i < n; i++) {
        all.push(i);
        if (s[i] == 'D') {
            d.push(i);
        } else {
            r.push(i);
        }
    }

    while ((int)all.size() > 1) {
        int p = all.front();
        all.pop();
        if (dead[p]) {
            continue;
        }

        int o = get(s[p] == 'R' ? d : r);
        if (o == -1) {
            putchar(s[p]);
            putchar('\n');
            return 0;
        }

        dead[o] = true;
        all.push(p);
        
    }

    int p = all.front();
    putchar(s[p]);
    putchar('\n');

    return 0;
}
