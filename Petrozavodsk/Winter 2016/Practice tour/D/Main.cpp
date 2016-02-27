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

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int l = 1, r;
char s[5];

int main() {
    scanf("%d", &r);

    while (l < r) {
        int mid = (l + r + 1) / 2;

        printf("? %d\n", mid);
        fflush(stdout);

        scanf("%s", s);

        if (strcmp(s, ">=") == 0) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    printf("! %d\n", l);
    
    return 0;
}
