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
const int MAXN = 10010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, a[MAXN];

struct Comp {
    bool operator () (int l, int r) const {
       // if (a[l] == a[r]) {
            int nl = max(a[(l - 1 + n) % n], a[(l + 1) % n]);
            int nr = max(a[(r - 1 + n) % n], a[(r + 1) % n]);

            if (a[l] == a[r])
                return nl < nr;                            
            return a[l] < a[r];
       // }
       // return a[l] < a[r];
    }
};  

set <int, Comp> Set;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);

            if (a[i] < 0) {
                Set.insert(i);
            }
        }
                                                            
        int ans = 0;
        while (!Set.empty()) {
            ans++;
            int idx = *Set.begin();
            Set.erase(Set.begin());
                    

            a[idx] *= -1;
            int l = (idx - 1 + n) % n;
            int r = (idx + 1) % n;

            Set.erase(l);
            Set.erase(r);
            
            a[l] -= a[idx];                                                
            a[r] -= a[idx];                                                        

            if (a[l] < 0) {
                Set.insert(l);
            }

            if (a[r] < 0) {
                Set.insert(r);
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}

/*cerr << idx << endl;
            for (int i = 0; i < n; i++) {
                cerr << a[i] << ' ';
            }
            cerr << endl;

            for (int i: Set) {
                cerr << i << ' ';
            }
            cerr << endl;*/