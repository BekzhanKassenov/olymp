/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "john"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 300010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
vector <pair <int, int> > a;

void compress(vector <pair <int, int> >& a) {
    vector <int> vec;

    for (auto p: a) {
        vec.push_back(p.first);
        vec.push_back(p.second);
    }

    sort(all(vec));
    vec.resize(unique(all(vec)) - vec.begin());

    for (auto& p: a) {
        p.first = lower_bound(all(vec), p.first) - vec.begin();
        p.second = lower_bound(all(vec), p.second) - vec.begin();
    }
}

bool cmp(const pair <int, int>& a, const pair <int, int>& b) {
    return a.first + a.second < b.first + b.second;
}

int x[MAXN], y[MAXN];

void update(int t[], int pos, int val) {
    for (int i = pos; i < MAXN; i |= i + 1) {
        t[i] += val;
    }
}

int sum(int t[], int pos) {
    int result = 0;
    for (int i = pos; i >= 0; i = (i & (i + 1)) - 1) {
        result += t[i];
    }

    return result;
}

int sum(int t[], int l, int r) {
    return sum(t, r) - sum(t, l - 1);
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    scanf("%d", &n);
    a.resize(n);

    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a[i].first, &a[i].second);
    }

    compress(a);

    sort(all(a), cmp);

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += sum(x, a[i].first + 1, MAXN - 2);
        ans += sum(y, a[i].second + 1, MAXN - 2);

        update(x, a[i].first, 1);
        update(y, a[i].second, 1);
    }

    printf("%I64d\n", ans);

    return 0;
}
