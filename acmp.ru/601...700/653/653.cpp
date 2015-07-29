#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 300;

int n, m, c[maxn], r[maxn], x;
pair <int, int> col[maxn], row[maxn];
int last_row, last_col;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++)
        scanf("%d", c + i);

    r[0] = (c[0] - 1) / m;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++)
            scanf("%d", &x);

        r[i] = (x - 1) / m;
    }

    for (int i = 0; i < m; i++) {
        int mn = i;

        for (int j = i + 1; j < m; j++) {
            if (c[j] < c[mn])
                mn = j;
        }

        if (mn != i) {
            col[last_col++] = make_pair(i + 1, mn + 1);
            swap(c[i], c[mn]);
        }
    }

    for (int i = 0; i < n; i++) {
        int mn = i;

        for (int j = i + 1; j < n; j++) {
            if (r[j] < r[mn])
                mn = j;
        }

        if (mn != i) {
            row[last_row++] = make_pair(i + 1, mn + 1);
            swap(r[i], r[mn]);
        }
    }

    printf("%d\n", last_row + last_col);

    for (int i = 0; i < last_col; i++)
        printf("C %d %d\n", col[i].first, col[i].second);

    for (int i = 0; i < last_row; i++)
        printf("R %d %d\n", row[i].first, row[i].second);

    return 0;
}
