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

int n, m, k, last;
bool used[maxn][maxn];
vector <pair <int, int> > ans[300 * 300];

void make_short(int x, int y, int dx, int dy) {
    ans[last].push_back(MP(x, y));
    used[x][y] = true;

    x += dx;
    y += dy;

    ans[last].push_back(MP(x, y));
    used[x][y] = true;

    last++;
    k--;
}

void put(int x, int y, int dx, int dy) {
    if (k == 1)
        make_long(x, y, dx, dy);
    else
        make_short(x, y, dx, dy);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d%d", &n, &m, &k);

    while (k) {
        if (n % 2 == 0) {
            for (int i = 0; i < n && k; i += 2) 
                for (int j = 0; j < m && k; j++)
                    put(i, j, 1, 0);

        } else if (m % 2 == 0) {
            for (int i = 0; i < n && k; i++)   
                for (int j = 0; j < m && k; j += 2)
                    put(i, j, 0, 1);

        } else {
            for (int j = 0; j < m && k; j += 2) {
                put(0, j, 0, 1);
            }

            for (int i = 1; i < n && k; i += 2) {
                put(i, m - 1, 1, 0);
            }
        }
    }

    return 0;
}
