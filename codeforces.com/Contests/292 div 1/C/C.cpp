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

long long d[MAXN], h[MAXN];
int n, m, a, b;
int tadd[4 * MAXN], tsub[4 * MAXN];

int fadd(int pos) {
    return h[pos] + d[pos];
}

int fsub(int pos) {
    return h[pos] - d[pos];
}

void build(int v, int l, int r) {
    if (l == r) {
        tadd[v] = tsub[v] = l;
        return;
    }

    int mid = (l + r) / 2;
    
    build(2 * v, l, mid);
    build(2 * v + 1, mid + 1, r);

    tadd[v] = tadd[2 * v];
    if (fadd(tadd[v]) < fadd(tadd[2 * v + 1])) {
        tadd[v] = tadd[2 * v + 1];
    }

    tsub[v] = tsub[2 * v + 1];
    if (fsub(tsub[v]) < fsub(tsub[2 * v])) {
        tsub[v] = tsub[2 * v];
    }
}

int getadd(int v, int l, int r, int ql, int qr) {
    if (ql > r || l > qr || l > r || ql > qr) {
        return -1;
    }

    if (ql <= l && r <= qr) {
        return tadd[v];
    }

    int mid = (l + r) / 2;

    int ansl = getadd(2 * v, l, mid, ql, qr);
    int ansr = getadd(2 * v + 1, mid + 1, r, ql, qr);

    int ans = ansl;
    if (ans == -1 || (ansr != -1 && fadd(ans) < fadd(ansr))) {
        ans = ansr;
    }

    return ans;
}

int getsub(int v, int l, int r, int ql, int qr) {
    //cout << l << ' ' << r << ' ' << ql << ' ' << qr << ' ' << tsub[v] << endl;
    
    if (ql > r || l > qr || l > r || ql > qr) {
        return -1;
    }

    if (ql <= l && r <= qr) {
        return tsub[v];
    }

    int mid = (l + r) / 2;

    int ansl = getsub(2 * v, l, mid, ql, qr);
    int ansr = getsub(2 * v + 1, mid + 1, r, ql, qr);

    int ans = ansr;
    if (ans == -1 || (ansl != -1 && fsub(ans) < fsub(ansl))) {
        ans = ansl;
    }

    return ans;
}

long long fans(const pair <int, int>& p) {
    return h[p.first] + h[p.second] + d[p.second] - d[p.first];
}

pair <int, int> solve(int l, int r) {
    l++, r--;

    //cout << l << ' ' << r << endl;

    pair <int, int> ans = make_pair(l, r);

    pair <int, int> ans1;
    ans1.first = getsub(1, 1, 2 * n, l, r);
    ans1.second = getadd(1, 1, 2 * n, ans1.first + 1, r);

    pair <int, int> ans2;
    ans2.second = getadd(1, 1, 2 * n, l, r);
    ans2.first = getsub(1, 1, 2 * n, l, ans2.second - 1);

    if (ans2.first != -1 && ans2.second != -1 && fans(ans1) > fans(ans)) {
        ans = ans1;
    }
    
    if (ans2.first != -1 && ans2.second != -1 && fans(ans2) > fans(ans)) {
        ans = ans2;
    }

    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) {
        scanf("%I64d", &d[i + 1]);
        d[i + n + 1] = d[i + 1];
    }

    for (int i = 1; i <= n; i++) {
        scanf("%I64d", &h[i]);
        h[i] *= 2;
        h[i + n] = h[i];
    }

    for (int i = 1; i <= 2 * n; i++) {
        d[i] += d[i - 1];
    }

    build(1, 1, 2 * n);

    while (m--) {
        scanf("%d%d", &a, &b);

        if (a <= b) {
            a += n;
            swap(a, b);
        }

        pair <int, int> result = solve(a, b);
        //cout << result.first << ' ' << result.second << endl;
        printf("%I64d\n", fans(result));
    }

    return 0;
}
