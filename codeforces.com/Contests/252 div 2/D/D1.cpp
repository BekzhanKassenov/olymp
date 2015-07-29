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
const int maxn = 3010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m, a[maxn], pos[maxn], temp[maxn];
int need;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
        a[i]--;
        pos[a[i]] = i;
    }

    int cnt = 0;
    copy(a, a + n, temp);

    for (int i = 0; i < n; i++) {
        if (temp[i] != i) {
            int k = pos[i];

            swap(temp[i], temp[k]);
            pos[temp[i]] = i;
            pos[temp[k]] = k;
            cnt++;
        }
    }

    scanf("%d", &m);

    vector <pair <int, int> > ans;

    if (cnt < m) {
        while (cnt < m) {
            for (int i = 1; i < n; i++) {
                if (a[i] == i || (a[a[i]] == i && a[i])) {
                    swap(a[0], a[i]);
                    ans.push_back(MP(0, i));
                    cnt++;
                    break;
                }
            }
        }
    } else {
        int p = 0;

        while (cnt > m) {
            while (a[p] == p)
                p++;

            ans.push_back(MP(min(p, a[p]), max(p, a[p])));
            swap(a[a[p]], a[p]);
            cnt--;
        }
    }

    printf("%u\n", ans.size());

    for (size_t i = 0; i < ans.size(); i++)
        printf("%d %d ", ans[i].F + 1, ans[i].S + 1);
    
    return 0;
}
