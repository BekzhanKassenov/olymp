/****************************************
**          Solution by NU #2          **
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
const int MAXN = 1010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, k, x;
vector <int> cnt[MAXN];
pair <int, int> ans[MAXN];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (x == -1)
            x++;

        cnt[x].push_back(i);
    }

    for (int i = 1; i < MAXN; i++) {
        while (cnt[i].size() > 0 && cnt[i].size() % k == 0) {
            for (int j = 0; j < k; j++) {
                int pos = cnt[i].back();
                cnt[i].pop_back();
                ans[pos] = make_pair(i, 1);
            }
        }
    } 
    
    return 0;
}
