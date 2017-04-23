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

int n, Q;
char s[MAXN];
int pr[10][MAXN];
int temp[MAXN];
int last6[MAXN], last7[MAXN];
int sum[10][MAXN];
queue <int> q[10];
int pos[10];

struct SegTree {
    int n;
    vector <int> t[4 * MAXN];

    void init(int a[], int n) {
        this->n = n;
        build(a, 1, 0, n - 1);
    }

    void build(int a[], int v, int l, int r) {
        if (l == r) {
            if (a[l] != -1) {
                t[v].push_back(a[l]);
            }
            return;
        }

        int mid = (l + r) / 2;
        build(a, 2 * v, l, mid);
        build(a, 2 * v + 1, mid + 1, r);

        t[v].resize(t[2 * v].size() + t[2 * v + 1].size());
        merge(all(t[2 * v]), all(t[2 * v + 1]), t[v].begin());
    }

    int query(int v, int l, int r, int ql, int qr) {
        if (l > qr || ql > r) {
            return 0;
        }

        if (ql <= l && r <= qr) {
            return t[v].end() - lower_bound(all(t[v]), ql);
        }

        int mid = (l + r) / 2;
        return query(2 * v, l, mid, ql, qr)
             + query(2 * v + 1, mid + 1, r, ql, qr);
    }

    int cnt(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};

int subsum(int dig, int l, int r) {
    if (l > r) {
        return 0;
    }

    int ans = sum[dig][r];
    if (l > 0) {
        ans -= sum[dig][l - 1];
    }

    return ans;
}

int get(int l, int r) {
    int bl = l, br = r;
    int pos7 = last7[r];
    int pos6 = -1;
    while (bl <= br) {
        int mid = (bl + br) / 2;
        int tpos6 = last6[mid];
        if (tpos6 == -1
         || (pr[2][tpos6] < pr[2][pos7]
          && pr[0][tpos6] < pr[0][pos7]
          && pr[1][tpos6] < pr[1][pos7])) {

            bl = mid + 1;
            pos6 = tpos6;
        } else {
            br = mid - 1;
        }
    }

    if (pos6 < l || pr[2][pos6] < l) {
        return -1;
    }

    int sumr = subsum(6, pos6 + 1, r);
    int sum1 = subsum(1, l, pos6);
    int sum0 = subsum(0, l, pr[1][pos6]);
    int sum2 = subsum(2, l, pr[0][pos6]);

    return sumr + min(min(sum1, sum0), sum2);
}

SegTree s6, s7;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d\n", &n, &Q);
    gets(s);

    for (int i = 0; i < 10; i++) {
        pos[i] = -1;    
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < n; j++) {
            pr[i][j] = -1;
        }
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == '2' || s[i] == '0' || s[i] == '1') {
            q[s[i] - '0'].push(i);
        }

        while (!q[1].empty()) {
            pos[1] = q[1].front();
            q[1].pop();
        }

        while (!q[0].empty() && q[0].front() < pos[1]) {
            pos[0] = q[0].front();
            q[0].pop();
        }

        while (!q[2].empty() && q[2].front() < pos[0]) {
            pos[2] = q[2].front();
            q[2].pop();
        }

        pr[2][i] = pos[2];
        pr[0][i] = pos[0];
        pr[1][i] = pos[1];
    }

    for (int i = 0; i < n; i++) {
        temp[i] = -1;
        if (s[i] == '6') {
            temp[i] = pr[2][i];
        }
    }
    s6.init(temp, n);
    for (int i = 0; i < n; i++) {
        temp[i] = -1;
        if (s[i] == '7') {
            temp[i] = pr[2][i];
        }
    }
    s7.init(temp, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            sum[j][i] = sum[j][i - 1];
        }

        sum[s[i] - '0'][i]++;
    }

    last6[0] = -1;
    for (int i = 1; i < n; i++) {
        last6[i] = last6[i - 1];
        if (s[i] == '6') {
            last6[i] = i;
        }
    }

    last7[0] = -1;
    for (int i = 1; i < n; i++) {
        last7[i] = last7[i - 1];
        if (s[i] == '7') {
            last7[i] = i;
        }
    }

    while (Q--) {
        int l, r;
        scanf("%d%d", &l, &r);

        int cnt7 = s7.cnt(l - 1, r - 1);
        int cnt6 = s6.cnt(l - 1, r - 1);

        if (cnt7 == 0) {
            puts("-1");
        } else {
           int val1 = get(l - 1, r - 1);
           if (val1 != -1) { 
               cnt6 = min(cnt6, val1);
           }
           printf("%d\n", cnt6);
        }
    }

    return 0;
}
