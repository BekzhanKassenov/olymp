/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

char kingw[2], lw[2], kingb[2];
bool used[8][8];

bool can_move() {
    int x = kingb[0] - 'a';
    int y = kingb[1] - '0' - 1;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == j)
                continue;

            int tx = x + i;
            int ty = y + j;

            if (tx >= 0 && tx < 8 && ty >= 0 && ty < 8) {
                if (!used[tx][ty]) {
                    return true;
                } else {
                    if (tx == lw[0] - 'a' && ty == lw[1] - '0' - 1) {
                        if (abs(kingw[0] - lw[0]) > 1 || abs(kingw[1] - lw[1]) > 1)
                            return true;
                    } 
                }
            }
        }
    }

    return false;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%c%c %c%c %c%c\n", kingw, kingw + 1, lw, lw + 1, kingb, kingb + 1);

    if (abs(kingw[0] - kingb[0]) <= 1 && abs(kingw[1] - kingb[1]) <= 1)
        puts("Strange");
    else {
        used[kingw[0] - 'a'][kingw[1] - '0' - 1] = true;

        int x = lw[0] - 'a';
        int y = lw[1] - '0' - 1;
        used[x][y] = true;

        for (int i = 1; i < 8; i++) {
            if (x + i < 8 && !used[x + i][y])
                used[x + i][y] = true;
            else
                break;
        }

        for (int i = 1; i < 8; i++) {
            if (x - i >= 0 && !used[x - i][y])
                used[x - i][y] = true;
            else
                break;
        }

        for (int i = 1; i < 8; i++) {
            if (y + i < 8 && !used[x][y + i])
                used[x][y + i] = true;
            else
                break;
             
        }

        for (int i = 1; i < 8; i++) {
            if (y - i >= 0 && !used[x][y - i])
                used[x][y - i] = true;
            else
                break;
        }

        x = kingw[0] - 'a';
        y = kingw[1] - '0' - 1;

        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (x + i >= 0 && x + i < 8 && y + j >= 0 && y + j < 8)
                    used[x + i][y + j] = true;
            }
        }

        if (used[kingb[0] - 'a'][kingb[1] - '0' - 1]) {
            if (can_move())
                puts("Check");
            else
                puts("Checkmate");
        } else {
            if (can_move())
                puts("Normal");
            else
                puts("Stalemate");
        }
    }

    return 0;
}
