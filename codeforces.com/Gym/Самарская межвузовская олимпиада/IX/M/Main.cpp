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

int t[4 * MAXN];
int n, k;
char s[MAXN];

void set_val(int v, int l, int r, int pos, int val) {
    if (l == r) {
        t[v] = val;
        return;
    }

    int mid = (l + r) / 2;
    if (pos <= mid) {
        set_val(2 * v, l, mid, pos, val);
    } else {
        set_vak(2 * v + 1, mid + 1, r, pos, val);
    }

    t[v] = min(t[2 * v], t[2 * v + 1]);
}

int get_min(int v, int l, int r, int ql, int qr) {
    if (ql > r || l > qr) {
        return INF;
    }

    if (ql <= l && r <= qr) {
        return t[v];
    }

    int mid = (l + r) / 2;
    return min(get_min(2 * v, l, mid, ql, qr), get_min(2 * v + 1, mid + 1, r, ql, qr));
}

int sum[MAXN][26];

void precalc() {
    sum[0][s[0] - 'a'] = 1;
    for (int i = 1; i < n; i++) {
        memcpy(sum[i], sum[i - 1], sizeof(sum[i]));
        sum[i][s[i] - 'a']++;
    }
}

int get_cnt(int l, int r) {
    int ans = 0;
    for (int i = 0; i < 26; i++) {
        int cnt = sum[r][i];
        if (l > 0) {
            cnt -= sum[l - 1][i];
        }

        ans += cnt > 0;
    }

    return ans;
}

int get_left_range(int pos) {
    int l = 0, r = pos;
    int ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (get_cnt(mid, pos) > k) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return ans;
}

int get_right_range(int pos) {
    int l = 0, r = pos;
    int ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (get_cnt(mid, pos) < k) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    return ans;
}

pair <int, int> get_range(int pos) {
    pair <int, int> res;

    int posl = get_left_range(pos);
    if (posl == -1) {
        if (get_cnt(0, pos) == k) {
            res.first = 0;
        }
    }
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d\n", &k);
    gets(s);
    n = strlen(s);

    precalc();
    
    return 0;
}
