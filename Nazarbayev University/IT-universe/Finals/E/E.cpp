#include <iostream>
#include <cstdio>

using namespace std;

const int MAX_LEVEL = 9;
const int MAX_N     = 300;

int table_max[MAX_LEVEL][MAX_N], table_min[MAX_LEVEL][MAX_N]; // Sparse tables
int level[MAX_N]; // level[i] is logarythm of i
int a[MAX_N][MAX_N], n, m, T;
int col_max[MAX_N], col_min[MAX_N];

inline void build() {
    for (int i = 0; i < m; i++) {
        table_max[0][i] = col_max[i];
        table_min[0][i] = col_min[i];
    }

    for (int l = 1; l <= level[m]; l++) {
        int prev_power = 1 << (l - 1); // 2 ^ (l - 1)

        for (int i = 0; i < m; i++) {
            table_max[l][i] = table_max[l - 1][i];
            table_min[l][i] = table_min[l - 1][i];

            if (i + prev_power < m) {
                table_max[l][i] = max(table_max[l][i], table_max[l - 1][i + prev_power]);
                table_min[l][i] = min(table_min[l][i], table_min[l - 1][i + prev_power]);
            }
        }
    }
}

inline bool check(int l, int r) {
    int lev = level[r - l];

    int mini = min(table_min[lev][l], table_min[lev][r - (1 << lev)]);
    int maxi = max(table_max[lev][l], table_max[lev][r - (1 << lev)]);

    return maxi - mini <= T;
}

int bin_search(int pos) {
    int ans = -1, l = pos, r = m - 1;

    while (l <= r) {
        int mid = (l + r) >> 1;

        if (check(pos, mid + 1)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return ans;
}

int main() {
    freopen("rectangle.in", "r", stdin);
    freopen("rectangle.out", "w", stdout);

    scanf("%d%d%d", &n, &m, &T);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    level[0] = 0;

    for (int i = 2; i <= m; i++)
        level[i] = level[i >> 1] + 1;

    int ans = 0;

    for (int top = 0; top < n; top++) {
        for (int j = 0; j < m; j++) {
            col_max[j] = a[top][j];
            col_min[j] = a[top][j];
        }

        for (int i = top; i < n; i++) {
            for (int j = 0; j < m; j++) {
                col_max[j] = max(col_max[j], a[i][j]);
                col_min[j] = min(col_min[j], a[i][j]);
            }


            build();

            for (int j = 0; j < m; j++) {
                int rr = bin_search(j);

                if (rr != -1)
                    ans = max(ans, (i - top + 1) * (rr - j + 1));
            }
        }
    }

    printf("%d\n", ans);
    
    return 0;
}
        