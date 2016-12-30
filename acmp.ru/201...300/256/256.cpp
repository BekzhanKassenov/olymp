#include <bits/stdc++.h>

using namespace std;

int dx[] = {-2, -1, 1, -1,  1, 2};
int dy[] = { 0, 1,  1, -1, -1, 0};

struct Que {
    static const int MAXN = 200010;

    int arr[MAXN];
    int head, tail, size;

    Que() {
        clear();
    }

    void clear() {
        size = 0;
        head = 0, tail = 0;
    }

    bool empty() const {
        return size == 0;
    }

    void push(int n) {
        arr[tail] = n;
        tail = (tail + 1) % MAXN;
        size++;
    }

    int pop() {
        int ret = arr[head];
        head = (head + 1) % MAXN;
        size--;
        return ret;
    }
};

int n, x, y, cnt;
char c;

namespace std {
    template <>
    struct hash <pair <int, int> > {
        size_t operator () (const pair <int, int>& p) const {
            size_t res = p.first;
            res <<= 32;

            return res ^ p.second;
        }
    };
}

unordered_map <pair <int, int>, int> dist;
priority_queue <pair <long long, pair <int, int> >,
                vector <pair <long long, pair <int, int> > >,
                greater <pair <long long, pair <int, int> > > > q; 

inline long long sqr(int n) {
    return n * n;
}

int bfs(int x, int y) {
    dist.emplace(make_pair(x, y), 0);

    q.emplace(sqr(x) + sqr(y), make_pair(x, y));

    while (!q.empty()) {
        int xx = q.top().second.first;
        int yy = q.top().second.second;
        long long roughdist = q.top().first;
        q.pop();

        int d = dist[make_pair(xx, yy)];

        if (xx == 0 && yy == 0)
            return d;

        for (int i = 0; i < 6; i++) {
            int tx = xx + dx[i];
            int ty = yy + dy[i];

            long long roughdist1 = sqr(tx) + sqr(ty);

            pair <int, int> np{tx, ty};
            if (!dist.count(np)) {
                if (roughdist1 > roughdist) {
                    continue;
                }

                q.emplace(roughdist1, np);
                dist.emplace(np, d + 1);
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
