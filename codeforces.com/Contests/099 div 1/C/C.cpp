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
    TREE,
    CLOSE
};

struct Event {
    int x;
    ETYPE type;

    int idx;
    int prob;

    bool operator < (const Event& ev) const {
        if (x != ev.x) {
            return x < ev.x;
        }

        return type < ev.type;
    }
};

int n, m;
double power[MAXN];
double prob[MAXN];
int cnt[110];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    vector <Event> vec;

    for (int i = 0; i < n; i++) {
        int a, h, l, r;
        scanf("%d%d%d%d", &a, &h, &l, &r);

        vec.push_back({a - h, OPEN, -1, 100 - l});
        vec.push_back({a - 1, CLOSE, -1, 100 - l});

        vec.push_back({a + 1, OPEN, -1, 100 - r});
        vec.push_back({a + h, CLOSE, -1, 100 - r});
    }

    for (int i = 0; i < m; i++) {
        int x;
        scanf("%d%lf", &x, &power[i]);

        vec.push_back({x, TREE, i, -1});
    }

    sort(all(vec));
    for (const auto& event: vec) {
        switch (event.type) {
            case OPEN:
                cnt[event.prob]++;
                break;

            case CLOSE:
                cnt[event.prob]--;
                break;

            case TREE:
                prob[event.idx] = 1.0;
                for (int i = 99; i >= 0; i--) {
                    if (cnt[i] > 0) {
                        double mul = pow(i * 0.01, cnt[i]);
                        if (mul < EPS) {
                            prob[event.idx] = 0;
                        } else {
                            prob[event.idx] *= mul;
                        }
                    }
                }
                if (prob[event.idx] < EPS) {
                    prob[event.idx] = 0;
                }
                break;

            default:
                break;
        }
    }

    double ans = 0;
    for (int i = 0; i < m; i++) {
        ans += prob[i] * power[i];
    }

    printf("%.10lf\n", ans);

    return 0;
}
