#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 110;

typedef unsigned int uint;

vector <uint> nets[MAXN];

uint read_net() {
    int a[4], b[4];

    scanf("%d.%d.%d.%d", &a[0], &a[1], &a[2], &a[3]);
    scanf("%d.%d.%d.%d", &b[0], &b[1], &b[2], &b[3]);

    uint ans = 0;

    for (int i = 0; i < 4; i++) {
        ans <<= 8;
        ans |= a[i] & b[i];
    }

    return ans;
}

bool edge(int from, int to) {
    for (int a: nets[from]) {
        for (int b: nets[to]) {
            if (a == b) {
                return true;
            }
        }
    }

    return false;
}

int n;
int dist[MAXN], par[MAXN];
bool used[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        int k;
        scanf("%d", &k);
        nets[i].resize(k);

        for (int j = 0; j < k; j++) {
            nets[i][j] = read_net();
        }
    }

    int start, end;
    scanf("%d%d", &start, &end);

    queue <int> q;
    q.push(start);
    dist[start] = 0;
    used[start] = true;
    par[start] = -1;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        if (v == end) {
            break;
        }

        for (int to = 1; to <= n; to++) {
            if (edge(v, to) && !used[to]) {
                q.push(to);
                dist[to] = dist[v] + 1;
                used[to] = true;
                par[to] = v;
            }
        }
    }

    if (!used[end]) {
        puts("No");
        return 0;
    }


    vector <int> path;
    int v = end;

    do {
        path.push_back(v);
    } while ((v = par[v]) != -1);

    reverse(path.begin(), path.end());

    puts("Yes");
    for (int x: path) {
        printf("%d ", x);
    }

    puts("");

    return 0;
}
