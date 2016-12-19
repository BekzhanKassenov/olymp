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

int n, k;
int t[MAXN];
vector <pair <int, int> > vec;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &k);

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &t[i]);
        if (t[i] < 0) {
            cnt++;
        }
    }

    if (cnt > k) {
        puts("-1");
        return 0;
    }

    k -= cnt;

    if (cnt == 0) {
        puts("0");
        return 0;
    }

    if (cnt == 1) {
        for (int i = 1; i <= n; i++) {
            if (t[i] == -1) {
                if (n - i <= k) {
                    puts("1");
                } else {
                    puts("2");
                }
                return 0;
            }
        }
    }

    int lastT = 0;
    for (int i = 1; i <= n; i++) {
        if (t[i] < 0) {
            if (lastT != 0 && i - lastT > 1) {
                vec.emplace_back(lastT, i);
            }

            lastT = i;
        }
    }

    int endDays = n - lastT;
    bool endWinter = k >= endDays;
    
    sort(all(vec), [](const pair <int, int>& a, const pair <int, int>& b) {
        int lena = a.second - a.first;
        int lenb = b.second - b.first;
        return lena < lenb
            || (lena == lenb && a < b);
    });

    int ans = 0;
    ans += 2 * vec.size();
    ans++; // first
    if (!endWinter) {
        ans++;
    }

    for (const auto& p : vec) {
        int len = p.second - p.first - 1;
        if (len <= k) {
            if (endWinter && endDays > k - len) {
                endWinter = false;
                ans--;
            } else {
                ans -= 2;
            }
            k -= len;
        }
    }

    printf("%d\n", ans);

    return 0;
}
