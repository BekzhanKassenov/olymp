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

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, X;
set <int> setL, setR;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &X);

    for (int i = 0; i < n; i++) {
        int dist, dir;
        scanf("%d%d", &dist, &dir);
        if (dir == 1) {
            setL.insert(dist);
        } else {
            setR.insert(dist);
        }
    }

    int dir = 1;
    int ans = 0;

    while (!setL.empty() || !setR.empty()) {
        if (dir == 1) {
            auto iter = setR.lower_bound(X);

            if (iter == setR.begin() || setR.empty()) {
                X = 0, dir = 0;
                ans++;
            } else {
                iter--;
                X = *iter;
                dir ^= 1;
                setR.erase(X);
            }
        } else {
            auto iter = setL.lower_bound(X);
            if (iter != setL.end()) {
                X = *iter;
                dir ^= 1;
                setL.erase(iter);
            } else {
                break;
            }
        }
    }

    if (dir == 1) {
        ans++;
    }

    if (!setL.empty() || !setR.empty()) {
        puts("-1");
        return 0;
    }

    printf("%d\n", ans);

    return 0;
}
