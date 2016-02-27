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
const int MAXN = 200010;
const int MAXA = 1296000;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

enum EVENT {
    OPEN,
    CLOSE
};

int n;
int x[MAXN], y[MAXN], phi[MAXN], alpha[MAXN];

double getUncovered() {
    vector <pair <int, EVENT> > vec;
    bool cut = false;
    for (int i = 0; i < n; i++) {
        vec.emplace_back(alpha[i], OPEN);

        if (alpha[i] + phi[i] > MAXA) {
            vec.emplace_back(MAXA - 1, CLOSE);
            vec.emplace_back(0, OPEN);
            vec.emplace_back((alpha[i] + phi[i]) % MAXA, CLOSE);
            cut = true;
        } else {
            vec.emplace_back(alpha[i] + phi[i], CLOSE);
        }
    }

    sort(all(vec));
    if (vec[0].first != 0) {
        return vec[0].first / 2.0;
    }

    int last = 0;
    int bal = 1;
    for (size_t i = 1; i < vec.size(); i++) {
        int prevBal = bal;

        if (vec[i].second == OPEN) {
            bal++;
        } else {
            bal--;
        }

        if (prevBal == 0 && bal == 1 && vec[i].first > last) {
            return (vec[i].first + last) / 2.0;
        }

        last = vec[i].first;
    }

    if (vec.back().first != MAXA - 1) {
        return (MAXA - 1 + vec.back().first) / 2.0;
    }

    if (!cut) {
        return MAXA - .5;
    }

    return -1;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d%d%d%d", &x[i], &y[i], &phi[i], &alpha[i]);
    }

    double angle = getUncovered();

    puts("YES");
    angle /= 3600;
    angle = (angle / 180) * PI;
    int ansx = 1e9 * cos(angle);
    int ansy = 1e9 * sin(angle);

    printf("%d %d\n", ansx, ansy);

    return 0;
}
