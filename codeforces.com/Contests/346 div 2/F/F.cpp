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
const int MAXN = 1010;
const int MAXG = MAXN * MAXN * 5;
const int di[] = {1, 0, 0, -1};
const int dj[] = {0, 1, -1, 0};

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;
long long k;
int a[MAXN][MAXN];
int parent[MAXN * MAXN];
int size[MAXN * MAXN];
bool added[MAXN][MAXN];

bool ok(int i, int j) {
    return 0 <= i && i < n &&
           0 <= j && j < m;
}

int f(int i, int j) {
    return i * m + j;
}

int getParent(int v) {
    if (parent[v] == v) {
        return v;
    }

    return parent[v] = getParent(parent[v]);
}

void unite(int a, int b) {
    a = getParent(a);
    b = getParent(b);

    if (a == b) {
        return;
    }

    if (size[a] < size[b]) {
        parent[a] = b;
        size[b] += size[a];
    } else {
        parent[b] = a;
        size[a] += size[b];
    }
}

int ans[MAXN][MAXN];
void dfsAns(int i, int j, int num, int& cnt) {
    if (cnt == 0) {
        return;
    }

    ans[i][j] = num;
    cnt--;

    for (int k = 0; k < 4; k++) {
        int ti = i + di[k];
        int tj = j + dj[k];

        if (ok(ti, tj) && ans[ti][tj] == 0 && a[ti][tj] >= num) {
            dfsAns(ti, tj, num, cnt);
        }
    }
}

void print_ans(int i, int j) {
    int cnt = k / a[i][j];
    dfsAns(i, j, a[i][j], cnt);

    puts("YES");
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            printf("%d ", ans[x][y]);
        }
        puts("");
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);
    scanf("%lld", &k);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    vector <pair <int, int> > vec;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            vec.emplace_back(i, j);
        }
    }

    sort(all(vec), [&](const pair <int, int>& lhs, const pair <int, int>& rhs) {
        return a[lhs.first][lhs.second] > a[rhs.first][rhs.second];
    });

    for (const auto& p: vec) {
        added[p.first][p.second] = true;
        
        int num = f(p.first, p.second);
        parent[num] = num;
        size[num] = 1;

        for (int k = 0; k < 4; k++) {
            int ti = p.first + di[k];
            int tj = p.second + dj[k];

            if (ok(ti, tj) && added[ti][tj]) {
                unite(num, f(ti, tj));
            }
        }

        int pnum = getParent(num);

        if (k % a[p.first][p.second] == 0 && size[pnum] >= k / a[p.first][p.second]) {
            print_ans(p.first, p.second);
            return 0;
        }
    }

    puts("NO");

    return 0;
}
