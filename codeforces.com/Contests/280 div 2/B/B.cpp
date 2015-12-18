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

enum ETYPE {
    OPEN,
    CHECK,
    CLOSE
};

int n, len;
int a[MAXN];

bool check(double d) {
    vector <pair <double, ETYPE> > events;

    events.emplace_back(0, CHECK);
    events.emplace_back(len, CHECK);

    for (int i = 0; i + 1 < n; i++) {
        events.emplace_back((a[i] + a[i + 1]) / 2.0, CHECK);
    }

    for (int i = 0; i < n; i++) {
        events.emplace_back(a[i] - d, OPEN);
        events.emplace_back(a[i] + d, CLOSE);
    }

    sort(all(events));
    
    int bal = 0;
    for (const auto& event: events) {
        switch (event.second) {
            case OPEN:
                bal++;
                break;
            
            case CLOSE:
                bal--;
                break;

            case CHECK:
                if (bal == 0) {
                    return false;
                }

                break;

            default:
                break;
        }
    }

    return true;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &len);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    sort(a, a + n);

    double ans = -1;
    double l = 0, r = 2 * len;

    
    for (int i = 0; i < 200; i++) {
        double mid = (l + r) / 2.0;

        if (check(mid)) {
            ans = mid;
            r = mid;
        } else {
            l = mid;
        }
    }

    printf("%.14lf\n", ans);

    return 0;
}
