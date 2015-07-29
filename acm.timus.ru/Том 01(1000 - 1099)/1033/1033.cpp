#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>

using namespace std;

#define PII pair <int, int>
#define F first
#define S second
#define MP make_pair

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
int n;
bool used[100][100];
char s[50][50];

int bfs(int i, int j) {
    queue <PII> q;
    q.push(MP(i, j));

    used[i][j] = true;

    int res = 0;

    while (!q.empty()) {
        PII cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            if (s[cur.F + dx[i]][cur.S + dy[i]] == '#')
                res++;
            else {
                if (!used[cur.F + dx[i]][cur.S + dy[i]]) {
                    used[cur.F + dx[i]][cur.S + dy[i]] = true;
                    q.push(MP(cur.F + dx[i], cur.S + dy[i]));
                }
            }
        }
    }

    return res;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
    #endif

    scanf("%d\n", &n);

    for (int i = 0; i <= n + 1; i++)
        s[0][i] = '#';

    for (int i = 1; i <= n; i++) {
        s[i][0] = '#';
        gets(s[i] + 1);
        s[i][n + 1] = '#';
    }

    for (int i = 0; i <= n + 1; i++)
        s[n + 1][i] = '#';

    int st = bfs(1, 1);
    
    if (!used[n][n]) {
        st += bfs(n, n);    
    }

    st -= 4;

    printf("%d", st * 9);

    return 0;
}
