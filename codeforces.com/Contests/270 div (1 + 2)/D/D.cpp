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
const int MAXN = 2010;
const set <pair <int, int> > EMP = set <pair <int, int> >();

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
int a[MAXN][MAXN];
bool used[MAXN];
int pr[MAXN];
vector <pair <int, int> > vec;

bool stup_check() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j && a[i][j] != 0)
                return false;

            if (i != j && (a[i][j] == 0 || a[i][j] != a[j][i]))
                return false;
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
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    if (!stup_check()) {
        puts("NO");
        return 0;
    }

    for (int i = 2; i <= n; i++)
        vec.push_back(make_pair(a[1][i], i));

    sort(all(vec));
    reverse(all(vec));

    for (size_t i = 0; i < vec.size(); i++) {
        int v = vec[i].second;

        int mn = 1;
        for (int i = 1; i <= n; i++) {
            if (a[v][i] != 0 && a[v][i] < a[v][mn])
                mn = i;
        }

        for (int i = 1; i <= n; i++) {
            if (a[v][i] != 0 && i != mn && a[v][i] != a[v][mn] + a[mn][i]) {
                puts("NO");
                return 0;
            }
        }

        for (int j = 1; j <= n; j++)
            a[v][j] = a[j][v] = 0;
    }

    puts("YES");

    return 0;
}
