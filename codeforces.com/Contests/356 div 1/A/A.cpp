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

bool query(int num) {
#ifndef ONLINE_JUDGE
    static int secret = -1;

    if (secret == -1) {
        srand(time(NULL));
        secret = rand() % 99 + 2;
        printf("Secret: %d\n", secret);
    }

    return secret % num == 0;
#else
    static char ans[20];
    printf("%d\n", num);
    fflush(stdout);

    scanf("\n%s", ans);

    return strcmp(ans, "yes") == 0;
#endif
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    int cnt = 0;
    for (int i: {2, 3, 5, 7}) {
        if (!query(i)) {
            continue;
        }

        cnt++;

        if (query(i * i)) {
            cnt++;
        }

        if (cnt > 1) {
            puts("composite");
            return 0;
        }
    }

    for (int i: {11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47}) {
        if (!query(i)) {
            continue;
        }

        cnt++;

        if (cnt > 1) {
            puts("composite");
            return 0;
        }
    }

    puts("prime");

    return 0;
}
