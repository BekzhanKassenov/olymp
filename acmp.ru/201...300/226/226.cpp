#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
 
using namespace std;
 
const int MAXN = 110;
 
int n, m;
long long dist[MAXN][MAXN];
 
long long read_dist() {
    static char buf[30];
    scanf(" %s", buf);

    long long a = 0;
    int cnt = 0;
    bool dot = false;

    for (int i = 0; buf[i]; i++) {
        if (buf[i] == '.') {
            dot = true;
        } else {
            if (dot) {
                cnt++;
            }
            a *= 10;
            a += buf[i] - '0';
        }
    }

    while (cnt < 3) {
        a *= 10;
        cnt++;
    }

    return a;
}
 
void print_dist(long long dist) {
    int m = dist % 1000;
    printf("%lld.%03d", dist / 1000, m);
}

void check(bool cond) {
    if (!cond) {
        puts("NO");
        exit(0);
    }
}

void tryset(int a, int b, long long d) {
    check(d >= 0);
    check(dist[a][b] == -1 || dist[a][b] == d);
    dist[a][b] = dist[b][a] = d;
}
 
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
     
    scanf("%d%d\n", &n, &m);
     
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = -1;
        }
    }
 
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        long long d = read_dist();
     
        if (d != 0) {
            tryset(a, b, d);
        } else {
            int l = min(a, b);
            int r = max(a, b);

            for (int j = l; j < r; j++) {
                tryset(j, j + 1, 0);
            }
        }
    }
 
    for (int i = 1; i <= n; i++) {
        check(dist[i][i] <= 0);
        dist[i][i] = 0;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i != j && i != k && k != j && dist[i][k] != -1 && dist[k][j] != -1) {
                    int l = min(i, j);
                    int r = max(i, j);
 
                    long long d = -1;
                    if (k < l) {
                        d = dist[k][r] - dist[k][l];
                    } else if (l < k && k < r) {
                        d = dist[l][k] + dist[k][r];
                    } else {
                        d = dist[k][l] - dist[k][r];
                    }

                    tryset(l, r, d);
                }
            }
        }
    }

    /*
    #define update(i, j, k, d) {\
        if (dist[i][j] != -1 && dist[i][k] != -1) { \
            updated |= dist[j][k] == -1; \
            tryset(k, j, d); \
        } \
    }
 
    while (true) {
        bool updated = false;
         
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                for (int k = 1; k < j; k++) {
                    update(i, j, k, dist[i][k] - dist[i][j]);
                }
            }
 
            for (int j = i; j <= n; j++) {
                for (int k = j + 1; k <= n; k++) {
                    update(i, j, k, dist[i][k] - dist[i][j]);
                }
            }

            for (int j = 1; j <= i; j++) {
                for (int k = i; k <= n; k++) {
                    update(i, j, k, dist[i][k] + dist[i][j]);
                }
            }
        }
 
        if (!updated) {
            break;
        }
    }
    */
    vector <long long> ans;
    for (int i = 1; i < n; i++) {
        check(dist[i][i + 1] != -1);
        ans.push_back(dist[i][i + 1]);
    }
 
    puts("YES");
    for (long long x : ans) {
        print_dist(x);
        putchar(' ');
    }
    puts("");
 
    return 0;
}
                