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

int a, b, T;
char op[10];
bool result;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d\n", &T);

    while (T--) {
        scanf("%d %s %d\n", &a, op, &b);

        if (strcmp(op, "!=") == 0) {
            result = (a != b);
        } else if (strcmp(op, "==") == 0) {
            result = (a == b);
        } else if (strcmp(op, "<") == 0) {
            result = (a < b);
        } else if (strcmp(op, "<=") == 0) {
            result = (a <= b);
        } else if (strcmp(op, ">") == 0) {
            result = (a > b);
        } else {
            result = (a >= b);
        }

        if (result) {
            puts("true");
        } else {
            puts("false");
        }
    }
    
    return 0;
}
