/*****************************************
**     Solution by Bekzhan Kassenov     **
*****************************************/

#include <bits/stdc++.h>

using namespace std;

#define by(T, x) [](const T& a, const T& b) { return a.x < b.x; }
#define all(x) (x).begin(), (x).end()

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

const double EPS = 1e-9;
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int t[MAXN];
int alive[MAXN];
void add(int pos, int val) {
    alive[pos] += val;
    for (int i = pos; i < MAXN; i |= i + 1) {
        t[i] += val;
    }
}

int sum(int pos) {
    int ans = 0;
    for (int i = pos; i >= 0; i = (i & (i + 1)) - 1) {
        ans += t[i];
    }
    return ans;
}

int sum(int l, int r) {
    if (l > r) {
        return 0;
    }

    return sum(r) - sum(l - 1);
}

int n;
int next_alive(int pos) {
    if (sum(pos, n) == 0) {
        if (pos != 1) {
            return next_alive(1);
        }

        return -1;
    }

    if (alive[pos]) {
        return pos;
    }

    int l = pos, r = n;
    int ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        int s = sum(pos, mid);

        if (s >= 1) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }

    return ans;
}

int a[MAXN];
vector <int> vec[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        vec[a[i]].push_back(i);
    }

    for (int i = 1; i <= n; i++) {
        add(i, 1);
    }

    long long ans = 0;
    int cur = 1;
    for (int num = 1; num < MAXN && cur > 0; num++) {
        assert(alive[cur] == 1);
        if (vec[num].empty()) {
            continue;
        }

        if (cur > vec[num].back()) {
            ans += sum(cur, n);
            cur = next_alive(1);
        }

        if (vec[num].size() == 1u) {
            ans += sum(cur, vec[num][0]);
            add(vec[num][0], -1);
            cur = next_alive(vec[num][0]);
            continue;
        }

        int idx = lower_bound(all(vec[num]), cur) - vec[num].begin();
        //cerr << cur << ' ' << idx << endl;

        int to = -1;
        if (idx != 0) {
            int pr = idx - 1;
            ans += sum(cur, n);
            ans += sum(1, vec[num][pr]);
            to = vec[num][pr];
        } else {
            ans += sum(cur, vec[num].back());
            to = vec[num].back();
        }

        for (int p : vec[num]) {
            add(p, -1);
        }

        cur = next_alive(to);

        //cerr << cur << ' ' << ans << endl;
        //cerr << endl;
    }

    printf("%lld\n", ans);
    
    return 0;
}
