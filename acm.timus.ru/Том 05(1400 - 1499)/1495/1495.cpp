#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000010;

int n;
bool used[MAXN];
int len[MAXN];
int par[MAXN];
int parn[MAXN];
int ans[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    if (n == 1) {
        puts("1");
        return 0;
    }

    if (n == 2) {
        puts("2");
        return 0;
    }

    queue <int> q;
    len[1] = 1;
    len[2] = 1;
    par[1] = -1;
    par[2] = -1;
    parn[1] = 1;
    parn[2] = 2;
    used[1] = true;
    used[2] = true;
    q.push(1);
    q.push(2);

    while (!q.empty()) {
        int m = q.front();
        q.pop();
        if (m == 0) {
            break;
        }

        for (int i = 1; i <= 2; i++) {
            int m1 = (m * 10 + i) % n;
            if (!used[m1] || (len[m1] == len[m] + 1 && parn[m] == 1 && parn[par[m1]] == 2)) {
                used[m1] = true;
                len[m1] = len[m] + 1;
                par[m1] = m;
                parn[m1] = i;
                q.push(m1);
            }
        }
    }

    if (!used[0]) {
        puts("Impossible");
        return 0;
    }

    int v = 0;
    int ansl = 0;
    do {
        ans[ansl++] = parn[v];
        v = par[v];
    } while (v != -1);

    for (int i = ansl - 1; i >= 0; i--) {
        printf("%d", ans[i]);
    }
    puts("");
    return 0;
}
