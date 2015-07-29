#include <cstdio>
#include <cmath>
#include <queue>
#include <map>

using namespace std;

#define MP make_pair

int dx[] = {-2, -1, 1, -1,  1, 2};
int dy[] = { 0, 1,  1, -1, -1, 0};

int n, x, y, cnt;
char c;

map <long long, int> dist;

int sqr(int n) {
    return n * n;
}

long long hash(int a, int b) {
    long long res = a;
    res <<= 32;
    res ^= b;

    return res;
}

int bfs(int x, int y) {
    vector <int> X, Y;

    dist[hash(x, y)] = 0;

    X.push_back(x);
    Y.push_back(y);

    for (size_t i = 0; i < X.size(); i++) {
        int xx = X[i];
        int yy = Y[i];

        int d = dist[hash(xx, yy)];

        if (xx == 0 && yy == 0)
            return d;

        int roughdist = sqrt(sqr(xx) + sqr(yy) + .0);

        for (int i = 0; i < 6; i++) {
            int tx = xx + dx[i];
            int ty = yy + dy[i];

            int roughdist1 = sqrt(sqr(tx) + sqr(ty) + .0);

            if (!dist.count(hash(tx, ty))) {
                if (roughdist1 > roughdist + 2)
                    continue;

                X.push_back(tx);
                Y.push_back(ty);
                dist[hash(tx, ty)] = d + 1;
            }
        }
    }

    return 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d\n", &n);

    for (int i = 0; i < n; i++) {
        scanf("%c %d\n", &c, &cnt);
        x += cnt * dx[c - 'X'];
        y += cnt * dy[c - 'X'];
    }
    
    printf("%d\n", bfs(x, y));
    
    return 0;
}
