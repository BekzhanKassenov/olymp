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
const int MAXN = 110;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

enum mBool {
    UNKNOWN,
    TRUE,
    FALSE
};

int T, Q, M;
mBool ans[MAXN][4];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d", &T);

    while (T--) {
        scanf("%d%d", &Q, &M);

        for (int i = 0; i < Q; i++) {
            for (int j = 0; j < 4; j++) {
                ans[i][j] = UNKNOWN;
            }
        }

        for (int p = 0; p < M; p++) {
            for (int i = 0; i < Q; i++) {
                char a, b;
                scanf("\n%c\n%c", &a, &b);

                if (b == 'T') {
                    ans[i][a - 'A'] = TRUE;
                } else {
                    ans[i][a - 'A'] = FALSE;
                }
            }
        }

        for (int i = 0; i < Q; i++) {
            char res = '?';

            for (int j = 0; j < 4; j++) {
                if (ans[i][j] == TRUE) {
                    res = j + 'A';
                }
            }

            if (res == '?') {
                int cnt = 0;

                for (int j = 0; j < 4; j++) {
                    if (ans[i][j] == FALSE) {
                        cnt++;
                    } else {
                        res = j + 'A';
                    }
                }

                if (cnt != 3) {
                    res = '?';
                }
            }

            printf("%c%c", res, " \n"[i == Q - 1]);
        }
    }
    
    return 0;
}
