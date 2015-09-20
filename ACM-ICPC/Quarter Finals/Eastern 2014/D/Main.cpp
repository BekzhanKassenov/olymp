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
const int MAXN = 310;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int money, oneroom, tworoom;
int n, m;
pair <int, int> fr[MAXN];

int ansadv = -1, ansid, alone;
bool found;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d%d%d", &money, &oneroom, &tworoom);

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d%d", &fr[i].first, &fr[i].second);
    }

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        int rooms, cost, adv;

        scanf("%d%d%d", &rooms, &cost, &adv);

        if (rooms == 1) {
            if (cost <= money && adv + oneroom > ansadv) {
                ansadv = adv + oneroom;
                ansid = i + 1;
                alone = -1;
                found = true;
            }
        } else {
            if (cost <= money && adv + tworoom > ansadv) {
                ansadv = adv + tworoom;
                ansid = i + 1;
                alone = -1;
                found = true;
            }

            for (int j = 0; j < n; j++) {
                if (cost <= 2 * money && cost <= 2 * fr[j].first && adv + fr[j].second > ansadv) {
                    ansadv = adv + fr[j].second;
                    ansid = i + 1;
                    alone = j + 1;
                    found = true;
                }
            }
        }
    }

    if (!found) {
        puts("Forget about apartments. Live in the dormitory.");
    } else if (alone == -1) {
        printf("You should rent the apartment #%d alone.\n", ansid);
    } else {
        printf("You should rent the apartment #%d with the friend #%d.\n", ansid, alone);
    }
    
    return 0;
}
