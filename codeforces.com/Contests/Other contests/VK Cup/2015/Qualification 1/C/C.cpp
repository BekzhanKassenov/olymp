/****************************************
**      Solution by NU: Black Kex      **
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

int m, k, T;
int a[MAXN], t[MAXN], r[MAXN];
char ans[MAXN];
bool used[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &T);

    while (T--) {
        scanf("%d%d", &m, &k);

        memset(ans, 'N', sizeof(char) * k);
        memset(used, false, sizeof(bool) * k);
        ans[k] = '\0';
        int upset = -1;
        int counter_before = 0;
        int counter = 0;

        for (int i = 0; i < k; i++) {
            scanf("%d", &a[i]);
        }

        for (int i = 0; i < m - 1; i++) {
            scanf("%d%d", &t[i], &r[i]);
            t[i]--;
            
            if (r[i] == 1 && upset == -1) {
                upset = i;
            }

            if (t[i] >= 0) {
                a[t[i]]--;
            } else {
                if (upset == -1) {
                    counter_before++;
                }

                counter++;
            }
        }

        if (upset == -1) {
            for (int i = 0; i < k; i++) {
                if (a[i] <= counter) {
                    ans[i] = 'Y';
                }
            }
        } else {
            for (int i = upset; i < m - 1; i++) {
                if (t[i] >= 0) {
                    used[t[i]] = true;
                }
            }

            int min_before_upset = -1;
            for (int i = 0; i < k; i++) {
                if (!used[i] && a[i] <= counter_before) {
                    ans[i] = 'Y'; 
                    
                    if (min_before_upset == -1 || a[i] < a[min_before_upset]) {
                        min_before_upset = i;
                    }
                }
            }

            if (min_before_upset >= 0) {
                int rest_counter = counter - a[min_before_upset];
                for (int i = 0; i < k; i++) {
                    if (a[i] <= rest_counter) {
                        ans[i] = 'Y';
                    }
                }
            }
        }

        puts(ans);
    }

    return 0;
}
