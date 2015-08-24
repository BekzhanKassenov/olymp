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

int T;
char s[11][11];

bool check_row(int row) {
    set <char> Set;

    for (int i = 0; i < 9; i++) {
        Set.insert(s[row][i]);
    }

    return Set.size() == 9u;
}

bool check_col(int col) {
    set <char> Set;

    for (int i = 0; i < 9; i++) {
        Set.insert(s[i][col]);
    }

    return Set.size() == 9u;
}

bool check_box(int bi, int bj) {
    int offset_i = bi * 3;
    int offset_j = bj * 3;

    set <char> Set;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            Set.insert(s[offset_i + i][offset_j + j]);
        }
    }

    return Set.size() == 9u;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d\n", &T);

    while (T--) {
        scanf("\n");
        for (int i = 0; i < 9; i++) {
            gets(s[i]);
        }

        bool result = true;
        for (int i = 0; i < 9; i++) {
            result &= check_row(i);
            result &= check_col(i);
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                result &= check_box(i, j);
            }
        }

        if (result) {
            puts("Valid");
        } else {
            puts("Invalid");
        }
    }
    
    return 0;
}
