#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = (int)2e9;

const int maxn = 200010;
int n, a[maxn], last, x;
int next[maxn], prev[maxn];
long long ans;

struct cmp {
    bool operator () (int aa, int bb) {
        return a[aa] < a[bb];
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        prev[i] = i - 1;
        next[i] = i + 1;
    }

    a[0] = a[n + 1] = INF;
    n = unique(a + 1, a + n + 1) - a - 1;
    multiset <int, cmp, std :: allocator <int> > Set(a + 1, a + n + 1);

    while (!Set.empty()) {
        int pos = *Set.begin();
        Set.erase(Set.begin());

        int diff = min(a[prev[pos]] - a[pos], a[next[pos] - a[pos]]);;
        ans += diff;

        if (a[prev[pos]] == a[next[pos]]) {
            if (prev[pos] == 0)
                continue;

            next[prev[prev[pos]]] = next[next[pos]];
            prev[next[next[pos]]] = prev[prev[pos]];

            Set.erase(
        }
    }

    return 0;
}
