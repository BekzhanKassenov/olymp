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
const int MAXN = 200010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct Server {
    long long cap;
    bool islow;
    int idx;

    void read() {
        int x;
        scanf("%I64d%d", &cap, &x);
        islow = x;
    }

    bool operator < (const Server& s) const {
        if (cap != s.cap)
            return cap > s.cap;

        return islow < s.islow;
    }
};

int n, x;
long long m, sum;
Server a[MAXN];
vector <Server> vec, ans;
int ansc;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d%I64d", &n, &m);

    for (int i = 1; i <= n; i++) {
        a[i].read();
        a[i].idx = i; 
    } 

    sort(a + 1, a + 1 + n);

    int pos = 0;

    for (int i = 1; i <= n; i++) {
        sum += a[i].cap;

        if (!a[i].islow) {
            vec.push_back(a[i]);
        } else {
            ans.push_back(a[i]);
            ansc++;
        }

        if (sum >= m) {
            pos = i;
            break;
        }
    }

    for (int i = pos + 1; i <= n && !vec.empty(); i++) {
        if (a[i].islow) {
            if (sum - vec.back().cap + a[i].cap >= m) {
                sum -= vec.back().cap - a[i].cap;
                ans.push_back(a[i]);
                ansc++;
                vec.pop_back();
            }
        }
    }

    while (!vec.empty()) {
        ans.push_back(vec.back());
        vec.pop_back();
    }

    printf("%d %d\n", ans.size(), ansc);

    for (size_t i = 0; i < ans.size(); i++)
        printf("%d ", ans[i].idx);
    
    puts("");
    
    return 0;
}
