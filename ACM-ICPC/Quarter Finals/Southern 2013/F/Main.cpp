/****************************************
**        Solution by NU PTZ 2016      **
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
const int MAXN = 300010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;
int t[MAXN];
double p[MAXN];
int finish[MAXN];
set <pair <int, int> > Set;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d%lf", &t[i], &p[i]);
    }

    for (int i = 0; i < m; i++) {
        Set.emplace(0, i);
    }

    int last = 0;
    while (!Set.empty()) {
        int moment = Set.begin()->first;
        int idx = Set.begin()->second;

        Set.erase(Set.begin());

        if (last < n) {
            finish[last] = moment + t[last];
            Set.emplace(finish[last], idx);
            last++;
        }
    }
    for (int i = 1; i < n; i++){
        finish[i] = max(finish[i], finish[i-1]);
    }
    double et = 0;
    double pp = 1;
    for (int i = 0; i < n; i++){
        if (i == n-1) et += finish[i]*pp;
        else et += finish[i]*pp*(1-p[i]);
        pp *= p[i];
    }
    printf("%.10lf\n", et);
    return 0;
}
