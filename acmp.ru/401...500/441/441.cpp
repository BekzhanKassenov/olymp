#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 100010;
const int MAXA = 2000010;

int n, a[MAXN], b[MAXN];
vector <int> mem[MAXA];
vector <int>* pos = mem + MAXA / 2;
int tree[MAXN];

void update(int pos, int val) {
    for (int i = pos; i < MAXN; i |= i + 1) {
        tree[i] += val;
    }
}

int sum(int pos) {
    int res = 0;
    for (int i = pos; i >= 0; i = ((i + 1) & i) - 1) {
        res += tree[i];
    }
    return res;
}

int sum(int l, int r) {
    int res = sum(r);
    if (l > 0) {
        res -= sum(l - 1);
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        pos[a[i]].push_back(i);
        update(i, 1);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }

    long long ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (pos[b[i]].empty()) {
            puts("-1");
            return 0;
        }

        int p = pos[b[i]].back();
        ans += sum(p + 1, MAXN - 1);

        pos[b[i]].pop_back();
        update(p, -1);
    }

    printf("%lld\n", ans);

    return 0;
}
