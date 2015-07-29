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

char s[10][10];
char name[6] = {'Q', 'R', 'B', 'N', 'P', 'K'};
char weight[6] = {9, 5, 3, 3, 1, 0};

int scoreWhite, scoreBlack;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    for (int i = 0; i < 8; i++) {
        gets(s[i]);
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 6; k++) {
                if (toupper(s[i][j]) == name[k]) {
                    if (isupper(s[i][j])) {
                        scoreWhite += weight[k];
                    } else {
                        scoreBlack += weight[k];
                    }

                    break;
                }
            }
        }
    }

    if (scoreWhite > scoreBlack) {
        puts("White");
    } else if (scoreWhite < scoreBlack) {
        puts("Black");
    } else {
        puts("Draw");
    }

    return 0;
}