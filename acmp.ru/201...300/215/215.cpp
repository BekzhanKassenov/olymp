#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

const int MAXN = 110;

int n, m, last = 1;
int a[MAXN][MAXN];
int zone[MAXN][MAXN];
bool used[MAXN * MAXN];

int di[] = {1, 0, 0, -1};
int dj[] = {0, 1, -1, 0};

inline bool ok(int i, int j) {
    return 0 <= i && i < n &&
           0 <= j && j < m;
}

void mark_zone(int i, int j, int znum) {
    queue <int> I, J;
    I.push(i);
    J.push(j);
    zone[i][j] = znum;

    while (!I.empty()) {
        int curi = I.front();
        int curj = J.front();

        I.pop();
        J.pop();
        
        for (int k = 0; k < 4; k++) {
            int ti = curi + di[k];
            int tj = curj + dj[k];

            if (ok(ti, tj) && zone[ti][tj] == 0 && a[ti][tj] == a[i][j]) {
                I.push(ti);
                J.push(tj);
                zone[ti][tj] = znum;
            }
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (zone[i][j] == 0) {
                mark_zone(i, j, last++);
            }
        } 
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 4; k++) {
                int ti = i + di[k];
                int tj = j + dj[k];

                if (ok(ti, tj) && a[ti][tj] < a[i][j]) {
                    used[zone[i][j]] = true;
                }
            }
        }
    }

    int ans = 0;

    for (int i = 1; i < last; i++) {
        if (!used[i]) {
            ans++;
        }
    }

    printf("%d\n", ans);

    return 0;
}
