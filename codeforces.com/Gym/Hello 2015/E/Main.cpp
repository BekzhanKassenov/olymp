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
const int MAXN = 410;
const int LG = 10;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m, q;
int a[MAXN][MAXN];

long long query(int k) {
    static int mx[MAXN], mn[MAXN];

    long long ans = 0;
    auto process = [&]() {
        deque <int> deqMax, deqMin;

        for (int l = 1, r = 1; l <= m; l++) {
            r = max(r, l);
            while (r <= m) {
                int valMax = mx[r];
                int valMin = mn[r];

                if (!deqMax.empty()) {
                    valMax = max(valMax, mx[deqMax.front()]);
                }

                if (!deqMin.empty()) {
                    valMin = min(valMin, mn[deqMin.front()]); 
                }

                if (valMax - valMin > k) {
                    break;
                }

                while (!deqMax.empty() && mx[r] >= mx[deqMax.back()]) {
                    deqMax.pop_back();
                }
                deqMax.push_back(r);

                while (!deqMin.empty() && mn[r] <= mn[deqMin.back()]) {
                    deqMin.pop_back();
                }
                deqMin.push_back(r);

                r++;
            }

            if (!deqMax.empty() && deqMax.front() == l) {
                deqMax.pop_front();
            }

            if (!deqMin.empty() && deqMin.front() == l) {
                deqMin.pop_front();
            }

            ans += r - l;
        }
    };

    for (int top = 1; top <= n; top++) {
        for (int j = 1; j <= m; j++) {
            mx[j] = a[top][j];
            mn[j] = a[top][j];
        }
        process();

        for (int bot = top + 1; bot <= n; bot++) {
            for (int j = 1; j <= m; j++) {
                mx[j] = max(mx[j], a[bot][j]);
                mn[j] = min(mn[j], a[bot][j]);
            }
            process();
        }
    }

    return ans;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d%d%d", &n, &m, &q);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    while (q--) {
        int k;
        scanf("%d", &k);
        printf("%lld\n", query(k));
    }
    
    return 0;
}
