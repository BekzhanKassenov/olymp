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
const int MAXN = 1010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
int p[MAXN], a[MAXN], rev[MAXN];
bool used[MAXN];

bool can_put(int pos, int val) {
    if (a[pos] == val) { // cycle
        return true;
    }

    if (a[pos] != -1) { // weird?
        return false;
    }

    a[pos] = val;
    used[val] = true;

    if (can_put(rev[val], pos)) {
        return true;
    }

    a[pos] = -1;
    used[val] = false;

    return false;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
        rev[p[i]] = i;
    }

    memset(a, 255, sizeof a);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n && a[i] == -1; j++) {
            if (!used[j] && can_put(i, j)) {
                break;
            }
        }
    }
    
    /*
    for (int i = 1; i <= n; i++) {
        if (used[i]) {
            continue;
        }

        for (int j = 1; j <= n; j++) {
            if (a[j] == -1 && can_put(j, i)) {
                break;
            }
        }
    }
    */

    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
