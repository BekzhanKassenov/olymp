/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, x[MAXN], y[MAXN];
int X, Y;
vector <int> mem[2 * MAXN];
vector <int>* cnt = mem + MAXN;
map <pair <int, int>, int> ans;
map <pair <int, int>, int> mx;
set <pair <int, int> > input;

int ansx[MAXN], ansy[MAXN];

void run(int xx, int yy) {
    int pos = 0;

    while (xx <= X && yy <= Y && input.count(make_pair(xx, yy))) {
        if (pos >= (int)cnt[yy - xx].size()) {
            puts("NO");
            exit(0);
        }

        ans[make_pair(xx, yy)] = cnt[yy - xx][pos];
        ansx[cnt[yy - xx][pos]] = xx;
        ansy[cnt[yy - xx][pos]] = yy;

        pos++;
        xx++, yy++;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d%d", &x[i], &y[i]);
        X = max(x[i], X);
        Y = max(y[i], Y);
        input.insert(make_pair(x[i], y[i]));
    }

    for (int i = 0; i < n; i++) {
        int w;
        scanf("%d", &w);
        cnt[w].push_back(i);
    }

    for (int i = 1; i <= Y; i++) {
        run(0, i);
    }

    run(0, 0);

    for (int i = 1; i <= X; i++) {
        run(i, 0);
    }

    for (const auto& point: input) {
        int xx = point.first;
        int yy = point.second;

        mx[make_pair(xx, yy)] = ans[make_pair(xx, yy)];

        if (xx > 0) {
            mx[make_pair(xx, yy)] = max(mx[make_pair(xx, yy)], mx[make_pair(xx - 1, yy)]);
        }

        if (yy > 0) {
            mx[make_pair(xx, yy)] = max(mx[make_pair(xx, yy)], mx[make_pair(xx, yy - 1)]);
        }

        if (mx[make_pair(xx, yy)] > ans[make_pair(xx, yy)]) {
            puts("NO");
            return 0;
        }
    }
    

    puts("YES");
    for (int i = 0; i < n; i++) {
        printf("%d %d\n", ansx[i], ansy[i]);
    }

    return 0;
}
