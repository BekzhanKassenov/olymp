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

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int m;
int h1, a1, xx1, yy1;
int h2, a2, xx2, yy2;
int period1, pred1;
int period2, pred2;
map <int, int> Map1, Map2;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &m);

    scanf("%d%d", &h1, &a1);
    scanf("%d%d", &xx1, &yy1);

    scanf("%d%d", &h2, &a2);
    scanf("%d%d", &xx2, &yy2);

    int temph1 = h1;
    for (int i = 0; ; i++) {
        if (Map1.count(temph1)) {
            period1 = i - Map[temph1];
            pred1 = Map[temph1];
            break;
        }

        temph1 = (1ll * xx1 * temph1 + yy1) % m;
    }

    int temph2 = h2;
    for (int i = 0; ; i++) {
        if (Map2.count(temph2)) {
            period2 = i - Map[temph2];
            pred2 = Map[temph2];
            break;
        }

        temph2 = (1ll * xx2 * temph2 + yy2) % m;
    }

    if (!Map1.count(a1) || !Map2.count(a2)) {
        puts("-1");
        return 0;
    }

    int pred = max(pred1, pred2);
    for (int i = 0; i <= pred; i++) {
        if (h1 == a1 && h2 == a2) {
            printf("%d\n", i);
            return 0;
        }
    }

    if (Map1[a1] < pred1 && Map2[a2] < pred2) {
        puts("-1");
        return 0;
    }



    return 0;
}
