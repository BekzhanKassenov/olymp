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
const int maxn = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m, h, t;
vector <int> g[maxn];
pair <int, int> edges[maxn];
vector <int> common, temp;
bool flag;
bool used[maxn];

void restore(int a, int b, int num) {
    int cnt = 0;

    for (size_t i = 0; i < g[a].size() && cnt < num; i++) {
        if (g[a][i] == b || used[g[a][i]])
            continue;

        used[g[a][i]] = true;

        if (!binary_search(all(common), g[a][i])) {
            printf("%d ", g[a][i] + 1);
            cnt++;
        } 
    }

    //cerr << endl << a + 1 << ' ' << b + 1 << ' ' << cnt << endl;

    while (cnt < num) {
        printf("%d ", temp.back() + 1);
        temp.pop_back();
        cnt++;
    }

    puts("");
}

bool check(int head, int tail) {
    if ((int)g[head].size() - 1 < h || (int)g[tail].size() - 1 < t)
        return false;

    common.clear();

    for (size_t i = 0; i < g[head].size() && (int)common.size() < h + t + 2; i++) {
        if (binary_search(all(g[tail]), g[head][i]))
            common.push_back(g[head][i]);
    } 

    if (int(g[head].size() + g[tail].size() - common.size()) < h + t + 2)
        return false;
    
    temp = common;
    
    puts("YES");
    printf("%d %d\n", head + 1, tail + 1);
    
    restore(head, tail, h);
    restore(tail, head, t);

    return true;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
                                                                                              
    scanf("%d%d%d%d\n", &n, &m, &h, &t);

    for (int i = 0; i < m; i++) {
        scanf("%d %d\n", &edges[i].first, &edges[i].second);

        g[--edges[i].first].push_back(--edges[i].second);
        g[edges[i].second].push_back(edges[i].first);
    }

    for (int i = 0; i < n; i++)
        sort(all(g[i]));

    for (int i = 0; i < m && !flag; i++) {
        int from = edges[i].first;
        int to = edges[i].second;

        if (check(from, to) || check(to, from))
            flag = true;
    }

    if (!flag)
        puts("NO");

    return 0;
}
