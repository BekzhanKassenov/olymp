#include <iostream>
#include <cstdio>

using namespace std;

const int di[] = {-2, -1, 1};
const int dj[] = {0, -2, -2};

bool consider[100][100];
long long dp[100][100];
int n;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &n);

    int startI = 50;
    int startJ = 0;
    int finishI = startI;
    int finishJ = startJ;

    int topI = startI;
    int topJ = startJ;
    int height = n;

    /*
    -*---*---*---*---
    ---*---*---*---*-
    -*---*---*---*---
    ---*---*---*---*-
    -*---*---*---*---
    ---*---*---*---*-
    -*---*---*---*---
    ---*---*---*---*-
    -*---*---*---*---
    */
    for (int iter = 1; iter < n; iter++) {
        int curI = topI;
        int curJ = topJ;

        for (int i = 0; i < height; i++) {
            consider[curI][curJ] = true;
            finishI = curI;
            finishJ = curJ;
            curI += 2;
        }

        topI--;
        topJ += 2;
        height++;
    }

    for (int iter = n; iter <= 2 * n - 1; iter++) {
        int curI = topI;
        int curJ = topJ;

        for (int i = 0; i < height; i++) {
            consider[curI][curJ] = true;
            finishI = curI;
            finishJ = curJ;
            curI += 2;
        }

        topI++;
        topJ += 2;
        height--;
    }

    dp[startI][startJ] = 1;
    for (int j = 0; j < 100; j++) {    
        for (int i = 0; i < 100; i++) {
            if (consider[i][j]) {
                for (int k = 0; k < 3; k++) {
                    int prevI = i + di[k];
                    int prevJ = j + dj[k];

                    if (0 <= prevI && prevI < 100
                     && 0 <= prevJ && prevJ < 100
                     && consider[prevI][prevJ]) {
                        dp[i][j] += dp[prevI][prevJ];
                     }
                }
            }
        }
    }

    printf("%lld\n", dp[finishI][finishJ]);
    
    return 0;
}
