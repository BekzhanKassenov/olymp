#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define F first
#define S second

const int maxn = 300010;

int t[maxn], a[maxn], pos[maxn], ans[maxn], n, m, l, r;
vector <int> divs[maxn];
vector <pair <int, int> > q[maxn];

void update(int pos) {
    for (int i = pos; i <= n; i |= i + 1)
        t[i]++;
}

int sum(int pos) {
    int res = 0;

    for (int i = pos; i > 0; i = (i & (i + 1)) - 1)
        res += t[i];

    return res;
}

int sum(int l, int r) {
    return sum(r) - sum(l - 1);
}

int main() {
    freopen("pairs.in", "r", stdin);
    freopen("pairs.out", "w", stdout);
               
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        pos[a[i]] = i;
    }

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        scanf("%d%d", &l, &r);

        q[r].push_back(make_pair(l, i));
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i + i; j <= n; j += i) {
            divs[max(pos[j], pos[i])].push_back(min(pos[j], pos[i]));
        }
    }

    for (int i = 1; i <= n; i++) {
        for (size_t j = 0; j < divs[i].size(); j++) {
            update(divs[i][j]);
        }

        for (size_t j = 0; j < q[i].size(); j++) {
            ans[q[i][j].S] = sum(q[i][j].F, i);
        }
    }

    for (int i = 0; i < m; i++)
        printf("%d\n", ans[i]);
    
    return 0;
}