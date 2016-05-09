#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

const int MAXN = 1010;
const int INF = (int)1e9;

int n, m;
int dp[MAXN];
int par[MAXN];
int digit[MAXN];
queue <int> q;

void restore(int num) {
    if (num == 0) {
        return;
    }

    restore(par[num]);
    printf("%d", digit[num]);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &m);

    n %= m;

    if (n == 0) {
        puts("0");
        return 0;
    }

    n = m - n;

    for (int i = 0; i < MAXN; i++) {
        dp[i] = INF;
        par[i] = -1;
    }

    dp[0] = 0;
    q.push(0);

    while (!q.empty()) {
        int num = q.front();
        q.pop();

        for (int dig = 0; dig < 10; dig++) {
            int tnum = (num * 10 + dig) % m;

            if (dp[tnum] > dp[num] + dig) {
                dp[tnum] = dp[num] + dig;
                par[tnum] = num;
                digit[tnum] = dig;
                q.push(tnum);
            }
        }
    }

    restore(n);

    return 0;
}
