#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int a[6][6];
int dist;
vector <int> ans = {1, 2, 3, 4, 5};

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    dist = a[1][2] + a[2][3] + a[3][4] + a[4][5];

    for (int i = 2; i <= 4; i++) {
        for (int j = 2; j <= 4; j++) {
            for (int k = 2; k <= 4; k++) {
                if (i != j && i != k && k != j && k != 3) {
                    int sum = a[1][i] + a[i][j] + a[j][k] + a[k][5];
                    if (sum < dist) {
                        dist = sum;
                        ans = {1, i, j, k, 5};
                    }
                }
            }
        }
    }

    printf("%d\n", dist);
    for (int x: ans) {
        printf("%d ", x);
    }

    puts("");
    return 0;
}
