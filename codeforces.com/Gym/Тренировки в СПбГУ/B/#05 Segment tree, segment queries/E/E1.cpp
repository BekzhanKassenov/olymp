#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN   = 100010;
const int MAXLEV = 17;

// Array and sparse table. 
// Actually, array can be stored in 0's row of array
int table[MAXLEV][MAXN], a[MAXN]; 

// level[i] is logarythm of i
int level[MAXN];

int n, m, u, v, ans;

inline void build() {
    level[0] = level[1] = 0;

    for (int i = 2; i <= n; i++)
        level[i] = level[i >> 1] + 1;

    for (int i = 0; i < n; i++)
        table[0][i] = a[i];

    for (int l = 1; l <= level[n]; l++) {
        int prev_power = 1 << (l - 1); // 2 ^ (l - 1)
        for (int i = 0; i < n; i++) {
            table[l][i] = table[l - 1][i];

            if (i + prev_power < n)
                table[l][i] = min(table[l][i], table[l - 1][i + prev_power]);
        }
    }
}

// Returns value of minimal element 
// on range [l, r)
inline int get_min(int l, int r) {
    int lev = level[r - l];

    return min(table[lev][l], table[lev][r - (1 << lev)]);
}

int main() {
    freopen("sparse.in", "r", stdin);
    freopen("sparse.out", "w", stdout);

    scanf("%d%d%d", &n, &m, &a[0]);
    
    scanf("%d%d", &u, &v);
    u--, v--;

    for (int i = 1; i < n; i++)
        a[i] = (23 * a[i - 1] + 21563) % 16714589;

    build();

    for (int i = 1; i <= m; i++) {
        ans = get_min(min(u, v), max(u, v) + 1);
        
        if (i != m) {
            u = (17 * (u + 1) + 751 + ans + 2 * i) % n;
            v = (13 * (v + 1) + 593 + ans + 5 * i) % n;
        }
    }

    printf("%d %d %d\n", u + 1, v + 1, ans);
    
    return 0;
}
