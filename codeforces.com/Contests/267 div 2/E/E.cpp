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
const int MAXN = 500010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, a[MAXN];
int t[4 * MAXN], prev[MAXN];
map <int, int> last;
map <int, int> cnt;
vector <int> ans;

int mmin(int a, int b) {
    if (prev[a] < prev[b]) {
        return a;
    }

    return b;
}

void update(int v, int l, int r, int pos) {
    if (pos < l || pos > r) {
        return;
    }

    if (l == r) {
        t[v] = pos;
        return;
    }

    int mid = (l + r) / 2;
    update(2 * v, l, mid, pos);
    update(2 * v + 1, mid + 1, r, pos);

    t[v] = mmin(t[2 * v], t[2 * v + 1]);
}

int get_min(int v, int l, int r, int ql, int qr) {
    if (ql > r || l > qr || ql > qr) {
        return MAXN - 1;
    }

    if (ql <= l && r <= qr) {
        return t[v];
    }

    int mid = (l + r) / 2;
    return mmin(get_min(2 * v, l, mid, ql, qr), get_min(2 * v + 1, mid + 1, r, ql, qr));
}

void clear(int l, int r) {
    prev[MAXN - 1] = INF;

    for (int i = l; i <= r; i++) {
        prev[i] = INF;
        update(1, 0, n - 1, i);
    }

    last.clear();
    cnt.clear();
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    clear(0, n - 1);

    int left = 0;

    for (int i = 0; i < n; i++) {
        cnt[a[i]]++;

        if (cnt[a[i]] == 4) {
            for (int j = 0; j < 4; j++) {
                ans.push_back(a[i]);
            }

            clear(left, i);
            left = i + 1;
        } else if (!last.count(a[i])) {
            prev[i] = INF;
            last[a[i]] = i;
            update(1, 0, n - 1, i);
        } else {
            int pos = get_min(1, 0, n - 1, last[a[i]] + 1, i - 1);

            if (prev[pos] < last[a[i]]) {
                ans.push_back(a[pos]);
                ans.push_back(a[i]);
                ans.push_back(a[pos]);
                ans.push_back(a[i]);
                clear(left, i);
                left = i + 1;
            } else {
                prev[i] = last[a[i]];
                last[a[i]] = i;
                update(1, 0, n - 1, i);
            }
        }
    }

    printf("%u\n", ans.size());
    for (size_t i = 0; i < ans.size(); i++) {
        printf("%d%c", ans[i], " \n"[i + 1 == ans.size()]);
    }
    
    return 0;
}
