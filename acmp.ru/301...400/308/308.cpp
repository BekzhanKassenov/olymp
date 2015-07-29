#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

const int maxn = 1010;
const int INF = maxn * maxn * maxn;

int a[3], sum, T;
int dp[maxn][maxn];

void move_water(int& aa, int& bb, int cap) {
    int diff = min(aa, cap - bb);
    aa -= diff;
    bb += diff; 
}

void init(queue <int>& q1, queue <int>& q2) {
    sum = max(a[0], max(a[1], a[2]));
    memset(dp, 255, sizeof dp);

    if (a[0] == sum) {
        q1.push(sum);
        q2.push(0);
        dp[sum][0] = 0;
    } else if (a[1] == sum) {
        q1.push(0);
        q2.push(sum);
        dp[0][sum] = 0;
    } else {
        q1.push(0);
        q2.push(0);
        dp[0][0] = 0;
    }
}

int bfs() {
    if (a[0] < T)   
        return -1;

    queue <int> f, s;
    init(f, s);

    int ans = INF;

    while (!f.empty()) {
        int first = f.front();
        f.pop();
        int second = s.front();
        s.pop();

        if (first == T)
            ans = min(ans, dp[first][second]);
        
        int third = sum - first - second;

        //cout << first << ' ' << second << ' ' << third << endl;

        int temp[3] = {first, second, third};
        
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == j)
                    continue;

                move_water(temp[i], temp[j], a[j]);
                                
                if (dp[temp[0]][temp[1]] == -1) {
                    dp[temp[0]][temp[1]] = dp[first][second] + 1;
                    f.push(temp[0]);
                    s.push(temp[1]);
                }
                
                temp[0] = first;
                temp[1] = second;
                temp[2] = third;
            }
        }
    }

    if (ans == INF)
        ans = -1;

    return ans;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d %d %d %d", &a[0], &a[1], &a[2], &T);
    
    int res = bfs();

    if (res != -1)
        printf("%d\n", res);
    else
        puts("IMPOSSIBLE");

    return 0;
}
