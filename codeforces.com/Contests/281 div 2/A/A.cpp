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

template <typename T>
inline T sqr(T n) {
    return n * n;
}

char home[25], guest[25];
bool used_home[110], used_guest[110];
int cnt_home[110], cnt_guest[110];
int minute, num;
int n;
char team, color;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    gets(home);
    gets(guest);
    
    scanf("%d\n", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d %c %d %c\n", &minute, &team, &num, &color);

        if (team == 'h') {
            if (color == 'y') {
                cnt_home[num]++;
            }

            if ((color == 'r' || cnt_home[num] >= 2) && !used_home[num]) {
                used_home[num] = true;
                printf("%s %d %d\n", home, num, minute);
            }
        } else {
            if (color == 'y') {
                cnt_guest[num]++;
            }

            if ((color == 'r' || cnt_guest[num] >= 2) && !used_guest[num]) {
                used_guest[num] = true;
                printf("%s %d %d\n", guest, num, minute);
            }
        }
    }

    return 0;
}
