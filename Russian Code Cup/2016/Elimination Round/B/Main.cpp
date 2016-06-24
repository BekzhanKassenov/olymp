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

int T;
int n, m;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &T);

    while (T--) {
        scanf("%d%d", &n, &m);

        int bad = 0;
        vector <pair <int, bool> > vec;

        for (int i = 0; i < m; i++) {
            int l, r;
            scanf("%d%d", &l, &r);
            if (l + r > n || l == n || r == n) {
                bad++;
                continue;
            }

            vec.push_back(make_pair(l, false));
            vec.push_back(make_pair(n - r, true));
        }

        int cntL = vec.size() / 2;
        int cntR = 0;
        sort(all(vec));

        int ans = cntL + cntR;
        int ptr = 0;
        while (ptr < (int)vec.size() && vec[ptr].first == 1) {
            ans--;
            ptr++;
        }

        int ansL = 1, ansR = n - 1;
        for (size_t i = 0; i < vec.size(); i++) {
            if (vec[i].second) {
                cntR++;
            } else {
                cntL--;
            }
            
            if (cntL + cntR < ans) {
                ans = cntL + cntR;
                ansL = vec[i].first;
                ansR = n - ansL;
            }
        }

        printf("%d %d\n", ansL, ansR);
    }
    
    return 0;
}
