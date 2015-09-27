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
const int MAXN = 10010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m, k;
int score[MAXN];
int mask[MAXN];
vector <int> ids[1 << 10][1 << 10];
stringstream ss;

int read_trait() {
    int mask = 0;
    int k;

    scanf("%d", &k);

    for (int i = 0; i < k; i++) {
        int x;
        scanf("%d", &x);
        mask |= 1 << (x - 1);
    }

    return mask;
}

bool cmp(int a, int b) {
    return score[a] > score[b];
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d%d", &n, &k);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &score[i]);
        mask[i] = read_trait();

        for (int mask1 = 0; mask1 < (1 << k); mask1++) {
            ids[mask1][mask[i] & mask1].push_back(i);
        }
    }

    for (int mask1 = 0; mask1 < (1 << k); mask1++) {
        for (int mask2 = 0; mask2 < (1 << k); mask2++) {
            sort(all(ids[mask1][mask2]), cmp);
        }
    }

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        int id;
        scanf("%d", &id);

        int mask1 = read_trait();
        int mask2 = mask[id] & mask1;

        printf("%d\n", lower_bound(all(ids[mask1][mask2]), id, cmp) - ids[mask1][mask2].begin() + 1);
    }

    return 0;
}