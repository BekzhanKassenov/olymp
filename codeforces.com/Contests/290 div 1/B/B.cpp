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
const int MAXN = 310;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, ans = -1;
int l[MAXN], c[MAXN];

int gcd(int a, int b) {
    while (a && b) {
        a %= b;
        swap(a, b);
    }

    return a + b;
}

void add_value(map <int, int>& Map, int pos, int val) {
    if (!Map.count(pos)) {
        Map[pos] = val;
    } else {
        Map[pos] = min(Map[pos], val);
    }

}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &l[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }

    map <int, int> Map;
    map <int, int> temp;

    for (int i = 0; i < n; i++) {
        for (map <int, int> :: iterator it = Map.begin(); it != Map.end(); it++) {
            int g = it->first;
            int cost = it->second;

            add_value(temp, g, cost);
            add_value(temp, gcd(g, l[i]), cost + c[i]);
        }

        add_value(temp, l[i], c[i]);
        swap(Map, temp);
        temp.clear();

        if (Map.count(1) && (ans == -1 || ans > Map[1])) {
            ans = Map[1];
        }
    }

    printf("%d\n", ans);
    
    return 0;
}
