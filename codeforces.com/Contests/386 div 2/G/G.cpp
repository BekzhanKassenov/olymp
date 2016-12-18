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
const int MAXN = 200010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, t, k;
int a[MAXN];
vector <int> nonleaf[MAXN], leaf[MAXN];
vector <pair <int, int> > g;

void print(const vector <int>& a) {
    for (int x : a) {
        cout << x << ' ';
    }
    cout << endl;
}

bool doEdges(const vector <int>& par, const vector <int>& a, const vector <int>& b) {
    if (par.size() > a.size() + b.size()) {
        return false;
    }

    int ptr = 0;
    for (int v : a) {
        g.emplace_back(par[ptr], v);
        ptr = (ptr + 1) % par.size();
    }

    for (int v : b) {
        g.emplace_back(par[ptr], v);
        ptr = (ptr + 1) % par.size();
    }

    return true;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d%d", &n, &t, &k);

    for (int i = 1; i <= t; i++) {
        scanf("%d", &a[i]);
    }

    nonleaf[0].push_back(1);

    int num = 2;
    for (int i = 1; i <= t; i++) {
        for (int j = 0; j < a[i]; j++) {
            nonleaf[i].push_back(num++);
        }
    }

    if (a[t] > k) {
        puts("-1");
        return 0;
    }

    swap(nonleaf[t], leaf[t]);
    k -= a[t];

    for (int i = t - 1; i >= 1; i--) {
        int cnt = min(a[i] - 1, k);
        while (cnt --> 0) {
            leaf[i].push_back(nonleaf[i].back());
            nonleaf[i].pop_back();
            k--;
        }
    }

    if (k > 0) {
        puts("-1");
        return 0;
    }

    for (int i = t - 1; i >= 0; i--) {
        cerr << i << ' ' << nonleaf[i].size() << ' ' << leaf[i + 1].size() + nonleaf[i + 1].size() << endl;
        if (!doEdges(nonleaf[i], leaf[i + 1], nonleaf[i + 1])) {
            puts("-1");
            return 0;
        }
    }

    printf("%d\n", n);
    for (const auto& p : g) {
        printf("%d %d\n", p.first, p.second);
    }

    return 0;
}
