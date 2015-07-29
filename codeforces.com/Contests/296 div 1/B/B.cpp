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

ostream& operator << (ostream& out, const pair <int, int>& p) {
    out << '{' << p.first << ", " << p.second << '}';
    return out;
}


int t[MAXN];
vector <int> nums;
int n, ans;
pair <int, int> a[MAXN];

void update(int pos, int val) {
//    printf("UPDATE: pos=%d val=%d\n", pos, val);
    for (int i = pos; i < n; i |= i + 1) {
        t[i] = max(t[i], val);
    }
}

int get_max(int pref) {
    int ans = 0;
    for (int i = pref; i >= 0; i = (i & (i + 1)) - 1) {
        ans = max(ans, t[i]);
    }

    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a[i].first, &a[i].second);
        nums.push_back(a[i].first + a[i].second);
    }

    sort(a, a + n);
    sort(all(nums));
    nums.resize(unique(all(nums)) - nums.begin());

    for (int i = 0; i < n; i++) {
        int pos1 = upper_bound(all(nums), a[i].first - a[i].second) - nums.begin();
        int pos2 = lower_bound(all(nums), a[i].first + a[i].second) - nums.begin();
        int size = 1;

        if (pos1 != 0) {
            pos1--;
            size = get_max(pos1) + 1;
        }

        update(pos2, size);
        ans = max(ans, size);
    }

    printf("%d\n", ans);

    return 0;
}
