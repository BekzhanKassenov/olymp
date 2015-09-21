/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define curr first
#define debt second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int months[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};

int n, x;

struct Letter {
    int delta;
    int moment;
    int num;
    int treePos;
};  

Letter a[MAXN];

bool cmpTime(const Letter& l1, const Letter& l2) {
    return l1.moment < l2.moment;
}

bool cmpPos(const Letter& l1, const Letter& l2) {
    return l1.num < l2.num;
}

pair <long long, long long> tree[4 * MAXN];

void print(int v) {

}

void update(int v, int l, int r, int pos, int val) {
    if (pos < l || pos > r) {
        return;
    }

    if (l == r) {
        if (val < 0) {
            tree[v].curr = 0;
            tree[v].debt = -val;
        } else {
            tree[v].curr = val;
            tree[v].debt = 0;
        }

        print(v);

        return;
    }

    int mid = (l + r) / 2;
    update(2 * v, l, mid, pos, val);
    update(2 * v + 1, mid + 1, r, pos, val);

    tree[v].curr = tree[2 * v + 1].curr + max(0ll, tree[2 * v].curr - tree[2 * v + 1].debt);
    tree[v].debt = -min(0ll, tree[2 * v].curr - tree[2 * v + 1].debt) + tree[2 * v].debt;

    print(v);
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    for (int i = 1; i < 12; i++) {
        months[i] += months[i - 1];
    }

    scanf("%d\n", &n);

    for (int i = 0; i < n; i++) {
        int delta, day, month, hour, minute;

        scanf("%d %d.%d %d:%d", &delta, &day, &month, &hour, &minute);

        a[i].delta = delta;
        a[i].moment = ((day + months[month - 1]) * 24 + hour) * 60 + minute;
        a[i].num = i;
    }

    sort(a, a + n, cmpTime);

    for (int i = 0; i < n; i++) {
        a[i].treePos = i;
    }

    sort(a, a + n, cmpPos);

    for (int i = 0; i < n; i++) {
        update(1, 0, n - 1, a[i].treePos, a[i].delta);

        printf("%I64d\n", -tree[1].debt);
    }

    return 0;
}
