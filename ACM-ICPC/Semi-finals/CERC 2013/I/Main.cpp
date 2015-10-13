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
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int T, n;
int a[MAXN];
vector <pair <int, int> > ans;

// i <= j
void do_swap(int i, int j) {
    if (i == j) {
        return;
    }

    int len = j - i + 1; // > 1

    if (len == 2) {
        ans.emplace_back(i, j);
        swap(a[i], a[j]);
    } else if (len & 1) {
        do_swap(j - 1, j);
        do_swap(i, j - 1);
        do_swap(j - 1, j);
    } else {
        int mid = (i + j) / 2;
        ans.emplace_back(i, j);
        ans.emplace_back(mid, mid + 1);
        ans.emplace_back(i, j);
        swap(a[i], a[j]);
    }
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d\n", &T);

    while (T--) {
        ans.clear();

        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]); 
        }

        for (int i = 1; i <= n; i++) {
            int pos = i;
            for (int j = i + 1; j <= n; j++) {
                if (a[j] == i) {
                    pos = j;
                    break;
                }
            }

            do_swap(i, pos);
        }

        printf("%u\n", ans.size());
        for (auto x: ans) {
            printf("%d %d\n", x.first, x.second);
        }
    }
    
    return 0;
}
