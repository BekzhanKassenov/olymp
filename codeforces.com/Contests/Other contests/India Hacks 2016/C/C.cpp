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
const int MAXN = 150010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
int a[MAXN];
vector <int> pos;

bool check() {
    for (int i = 1; i + 1 <= n; i++) {
        if (i % 2 == 1) {
            if (a[i] >= a[i + 1]) {
                return false;
            }
        } else {
            if (a[i] <= a[i + 1]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif 

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 1; i + 1 <= n; i++) {
        if (i % 2 == 1) {
            if (a[i] >= a[i + 1]) {
                pos.push_back(i);
                pos.push_back(i + 1);
            }
        } else {
            if (a[i] <= a[i + 1]) {
                pos.push_back(i);
                pos.push_back(i + 1);
            }
        }
    }

    sort(all(pos));
    pos.resize(unique(all(pos)) - pos.begin());

    if (pos.size() > 20) {
        puts("0");
        return 0;
    }

    int ans = 0;
    for (size_t i = 0; i < pos.size(); i++) {
        for (size_t j = i + 1; j < pos.size(); j++) {
            int p1 = pos[i], p2 = pos[j];
            swap(a[p1], a[p2]);

            if (check()) {
                ans++;
            }

            swap(a[p1], a[p2]);
        }
    }

    printf("%d\n", ans);

    return 0;
}
