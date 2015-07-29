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
const int MAXN = 15;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int counter[MAXN];
int last[MAXN];
queue <int> card[MAXN];
int n, T, x;
bool win;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d", &T);

    for (int casenum = 1; casenum <= T; casenum++) {
        scanf("%d", &n);

        win = true;
        for (int i = 0; i < n; i++) {
            counter[i] = 1;
            last[i] = -1;

            while (!card[i].empty()) {
                card[i].pop();
            }
        }

        for (int i = 0; i < 52; i++) {
            scanf("%d", &x);
            card[0].push(x);
        }

        int cnt = 0;
        while (win) {
            bool non_empty = true;

            for (int i = n - 1; i >= 0; i--) {
                if (!card[i].empty()) {
                    non_empty = false;
                    int c = card[i].front();
                    card[i].pop();

                    if (c == counter[i]) {
                        last[i] = c;
                        cnt = 0;

                        if (i < n - 1) {
                            card[i + 1].push(c);
                        }
                    } else {
                        card[i].push(c);
                    }

                    counter[i]++;

                    if (counter[i] > 13) {
                        counter[i] = 1;
                    }
                }
            }

            if (non_empty) {
                break;
            }
            cnt++;

            if (cnt > 120) {
                win = false;
            }
        }

        printf("Case %d: ", casenum);
        if (!win) {
            puts("unwinnable");
        } else {
            for (int i = 0; i < n; i++) {
                printf("%d ", last[i]);
            }
            puts("");
        }
    }
    
    return 0;
}
