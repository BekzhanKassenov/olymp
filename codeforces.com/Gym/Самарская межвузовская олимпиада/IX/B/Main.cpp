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
int a[MAXN];
vector <int> pos;
vector <pair <int, int> > ans;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (a[i] == i) {
            pos.push_back(i);
        }
    }


    while ((int)pos.size() > 1) {
        int pos1 = pos.back();
        pos.pop_back();
        int pos2 = pos.back();
        pos.pop_back();

        ans.push_back({pos1, pos2});
    }

    if (pos.size() == 1) {
        for (int i = 1; i <= n; i++) {
            if (i != pos[0]) {
                ans.push_back({i, pos[0]});
                break;
            }
        }
    }

    printf("%d\n", (int)ans.size());
    for (auto p: ans) {
        printf("%d %d\n", p.first, p.second);
    }
    
    return 0;
}
