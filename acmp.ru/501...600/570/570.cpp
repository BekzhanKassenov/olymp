#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 1010;

char s[1010][1010];
int sum[1010][1010];
int n, m;
int mxx = -1, mxy = -1, mnx = maxn, mny = maxn;

bool square(int x, int y, int _x, int _y) {
    if (_x - x != _y - y) {
        return false;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d %d\n", &n, &m);

    for (int i = 1; i <= n; i++)
        gets(s[i] + 1);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            sum[i] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
            
            if (s[i][j] == '*') {
                mxx = max(mxx, i);
                mnx = min(mnx, i);

                mxy = max(mxy, j);
                mny = min(mny, j);
                
                sum[i]++;
            }
        }
    }

    if (mxx == -1) {
        puts("SQUARE");
        return 0;
    }

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (square(mnx + i, mny + j, mxx + k, mxy + l)) {
                        puts("SQUARE");
                        return 0;
                    }
                }
            }
        }
    }

    puts("CIRCLE");

    return 0;
}
