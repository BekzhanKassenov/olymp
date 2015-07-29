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
int a[MAXN];
bool used[MAXN][2];

bool ok(int x) {
    return 0 <= x && x < n;
}

struct vec {
    int pos;
    int dir;

    vec() : pos(0), dir(1) { }

    int move() {
        if (!ok(pos + dir)) {
            dir *= -1;
        }

        int diff = a[pos];
        pos += dir;
        diff -= a[pos];

        return abs(diff);
    }

    bool isused() {
        if (dir == 1) {
            if (!used[pos][false]) {
                used[pos][false] = true;
                return false;
            }

            return true;
        } else {
            if (!used[pos][true]) {
                used[pos][true] = true;
                return false;
            }

            return true;
        }
    }
};

int m, b[MAXN], cnt[MAXN];
int num;
long long ans = -1;

void upd_cnt(int x, int delta) {
    if (cnt[x] + delta == 0) {
        num--;
    } else if (cnt[x] == 0) {
        num++;
    }

    cnt[x] += delta;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
        b[i]--;
        upd_cnt(b[i], 1);
    }

    vec front, back;
    long long sum = 0;
    upd_cnt(0, -1);

    for (int i = 0; i < m - 1; i++) {
        sum += front.move();
        upd_cnt(front.pos, -1);
    }

    if (num == 0) {
        ans = sum;
    }

    for (int i = 1; ; i++) {
        sum += front.move();
        upd_cnt(front.pos, -1);

        upd_cnt(back.pos, 1);
        sum -= back.move();

        if (back.isused()) {
            break;
        }

        if (num == 0) {
            if (ans == -1) {
                ans = sum;
            } else if (ans != sum) {
                puts("-1");
                return 0;
            }
        }
    }

    printf("%I64d\n", ans);
    
    return 0;
}
