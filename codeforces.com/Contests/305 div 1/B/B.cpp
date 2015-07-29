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

int n;
int a[MAXN], ans[MAXN];
int flag[4 * MAXN];
int l[MAXN], r[MAXN];
vector <int> st;

void push(int v, int l, int r) {
    if (l > r) {
        return;
    }

    if (l == r) {
        ans[l] = max(ans[l], flag[v]);
        flag[v] = 0;
        return;
    }
    
    flag[2 * v] = max(flag[2 * v], flag[v]);
    flag[2 * v + 1] = max(flag[2 * v + 1], flag[v]);

    flag[v] = 0;
}

void update(int v, int l, int r, int ql, int qr, int val) {
    push(v, l, r);

    if (l > r || ql > r || l > qr) {
        return;
    }

    if (ql <= l && r <= qr) {
        flag[v] = max(flag[v], val);
        push(v, l, r);
        return;
    }

    int mid = (l + r) / 2;

    update(2 * v,     l,       mid, ql, qr, val);
    update(2 * v + 1, mid + 1, r,   ql, qr, val);
}

void push_all(int v, int l, int r) {
    if (l > r) {
        return;
    }

    push(v, l, r);

    if (l == r) {
        return;
    }

    int mid = (l + r) / 2;
    push_all(2 * v, l, mid);
    push_all(2 * v + 1, mid + 1, r);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.back()] >= a[i]) {
            r[st.back()] = i - 1;
            st.pop_back();
        }

        if (st.empty()) {
            l[i] = 0;
        } else {
            l[i] = st.back() + 1;
        }

        st.push_back(i);
    }

    while (!st.empty()) {
        r[st.back()] = n - 1;
        st.pop_back();
    }

    for (int i = 0; i < n; i++) {
        update(1, 1, n, i - l[i] + 1, r[i] - l[i] + 1, a[i]);
    }

    push_all(1, 1, n);

    for (int i = 1; i <= n; i++) {
        printf("%d ", ans[i]);
    }

    puts("");

    return 0;
}
