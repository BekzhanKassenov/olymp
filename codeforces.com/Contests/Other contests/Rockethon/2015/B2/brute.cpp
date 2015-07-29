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

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);
    vector <int> p(n);
    vector <vector <int> > ans[1000 + 10];
    int mxsum = 0;;

    for (int i = 0; i < n; i++) {
        p[i] = i + 1;
    }
                    
    do {
        int sum = 0;

        for (int i = 0; i < n; i++) {
            int mnp = p[i];
            for (int j = i; j < n; j++) {
                mnp = min(mnp, p[j]);
                sum += mnp;
            }
        }
        ans[sum].push_back(p);
        mxsum = max(mxsum, sum);
    } while (next_permutation(all(p)));

    for (size_t j = 0; j < ans[mxsum].size(); j++) {
        printf("%3d: ", j + 1);
        for (int i = 0; i < n; i++) {
            printf("%d ", ans[mxsum][j][i]);
        }
        puts("");
    }

    return 0;
}
