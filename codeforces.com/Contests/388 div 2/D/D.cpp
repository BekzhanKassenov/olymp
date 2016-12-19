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
int a[MAXN], b[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &a[i], &b[i]);
    }

    vector <int> vec;
    vec.emplace_back(n);
    set <int> del;
    del.insert(a[n]);

    auto getPrev = [&del](int x) {
        int temp = x;
        do {
            temp--;
        } while (temp >= 0 && del.count(a[temp]));

        return temp;
    };

    int pr = getPrev(n);
    while (pr > 0) {
        int pp = getPrev(pr);
        while (pp >= 0 && a[pp] == a[pr]) {
            pr = pp;
            pp = getPrev(pr);
        }

        vec.push_back(pr);
        del.insert(a[pr]);
        pr = pp;
    }

    vec.push_back(0);

    int q;
    scanf("%d", &q);

    while (q--) {
        int k;
        scanf("%d", &k);

        vector <int> query(k);
        for (int i = 0; i < k; i++) {
            scanf("%d", &query[i]);
        }

        sort(all(query));

        int ans = n;
        for (size_t i = 0; i + 1 < vec.size(); i++) {
            if (binary_search(all(query), a[vec[i]])) {
                ans = vec[i + 1];
            } else {
                break;
            }   
        }

        printf("%d %d\n", a[ans], b[ans]);
    }

    return 0;
}
