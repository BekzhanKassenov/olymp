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
const int MAXN = 500010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, q, x;
int a[MAXN], cnt[MAXN];
int parity[MAXN];
bool take[MAXN];

int get(int num) {
    int cur = 0;

    if (num != 1) {
        if (parity[num] == 1) {
            cur += cnt[num];
        } else {
            cur -= cnt[num];
        }
    }

    for (int j = 2; j * j <= num; j++) {
        if (num % j == 0) {
            if (parity[j] == 1) {
                cur += cnt[j];
            } else {
                cur -= cnt[j];
            }

            if (j * j != num) {
                if (parity[num / j] == 1) {
                    cur += cnt[num / j];
                } else {
                    cur -= cnt[num / j];
                }
            }
        }
    }

    return cur;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &q);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 2; i < MAXN; i++) {
        bool found = false;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                int temp = i;

                while (temp % j == 0) {
                    temp /= j;
                }
                parity[i] = parity[temp] ^ 1;
                found = true;
                break;
            }
        }

        if (!found) {
            parity[i] = 1;
        }
    }

    int ans = 0;
    int cursize = 0;

    while (q--) {
        scanf("%d", &x);
        x--;

        int num = a[x];
        if (take[x]) {
            cursize--;
            cnt[num]--;

            for (int j = 2; j * j <= num; j++) {
                if (num % j == 0) {
                    cnt[j]--;

                    if (j * j != num) {
                        cnt[num / j]--;
                    }
                }
            }

            ans -= cursize - get(num);
        } else {
            ans += cursize - get(num);
                              
            cursize++;
            cnt[num]++;
            for (int j = 2; j * j <= num; j++) {
                if (num % j == 0) {
                    cnt[j]++;

                    if (j * j != num) {
                        cnt[num / j]++;
                    }
                }
            }
        }

        take[x] ^= 1;

        printf("%d\n", ans);
    }
    
    return 0;
}
