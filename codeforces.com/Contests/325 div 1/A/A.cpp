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
const int MAXN = 4010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
long long v[MAXN], d[MAXN], p[MAXN];
bool used[MAXN];
vector <int> ans;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%I64d%I64d%I64d", &v[i], &d[i], &p[i]);
    }

    for (int i = 0; i < n; i++) {
        if (used[i]) {
            continue;
        }

        ans.push_back(i + 1);
        used[i] = true;

        long long addend = 0;
        for (int j = i + 1; j < n && (v[i] > 0 || addend > 0); j++) {
            if (used[j]) {
                continue;
            }

            p[j] -= v[i] + addend;
            if (p[j] < 0) {
                addend += d[j];
                used[j] = true;
            }

            v[i] = max(v[i] - 1, 0LL);
        }
    }

    printf("%u\n", ans.size());
    for (auto x: ans) {
        printf("%d ", x);
    }
    puts("");
    
    return 0;
}
