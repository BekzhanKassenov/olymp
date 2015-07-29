#include <iostream>
#include <cstdio>

using namespace std;

int dist[16][16][31];
int n, k;
char s[16][16];
int di[] = {1, 0, 0, -1};
int dj[] = {0, 1, -1, 0};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    scanf("%d%d\n", &n, &k);

    for (int i = 0; i < n; i++)
        gets(s[i]);

    dist[0][0][0] = 1;

    for (int kk = 1; kk <= k; kk++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (s[i][j] != '1') {
                    for (int z = 0; z < 4; z++) {
                        int ti = i + di[z];
                        int tj = j + dj[z];

                        if (ti >= 0 && ti < n && tj >= 0 && tj < n)
                            dist[i][j][kk] += dist[ti][tj][kk - 1];
                    }
                }
            }
        }
    } 

    printf("%d\n", dist[n - 1][n - 1][k]);

    return 0;
}
