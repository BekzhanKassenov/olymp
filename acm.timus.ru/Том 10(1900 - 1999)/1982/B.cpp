#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define all(x) (x).begin(), (x).end()

const int maxn = 300;
int g[maxn][maxn];
int par[maxn];
int k, n, x;

struct edge {
    int a, b, cost;
    edge() {}

    edge(int a, int b, int cost) : a(a), b(b), cost(cost) {}
    
    bool operator < (const edge& e) const {
        return cost < e.cost;
    }
};

vector <edge> q;
bool is_el[maxn];

int get_par(int a) {
    if (par[a] == a)
        return a;

    return (par[a] = get_par(par[a]));
}

void un(int a, int b, bool flag) {
    a = get_par(a);
    b = get_par(b);
    
    par[b] = a;
    if (flag)
        for (int i = 0; i < n; i++)
            if (get_par(i) == a)
                is_el[i] = true;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
    #endif

    cin >> n >> k;

    for (int i = 0; i < k; i++) {
        cin >> x;
        is_el[x - 1] = true;
    }

    for (int i = 0; i < n; i++) {
        par[i] = i;
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
            if (i > j)
                q.push_back(edge(i, j, g[i][j]));
        }
    }

    int ans = 0;
    sort(all(q));

    for (size_t i = 0; i < q.size(); i++) {
        if (is_el[q[i].a] && is_el[q[i].b])
            continue;

        
        ans += q[i].cost;
        un(q[i].a, q[i].b, (is_el[q[i].a] || is_el[q[i].b]));
    }
    cout << ans << endl;
    return 0;
}
