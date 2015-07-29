/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define a first
#define b second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))

typedef pair <int, int> st;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);
const int maxn = 1010;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

int n, m, q, t, x, y;
set <st> X[maxn], Y[maxn];
bool field[maxn][maxn];

inline void build_x(int col) {
    int start, end;
    bool started = false;
    X[col].clear();

    for (int i = 1; i <= n; i++) {
        if (field[i][col]) {
            if (started) {
                end++;
            } else {
                started = true;
                start = end = i;
            }
        } else {
            if (started) {
                X[col].insert(st(start, end));
                started = false;
            }
        }
    }

    if (started) {
        X[col].insert(st(start, end));
    }
}

inline void build_y(int row) {
    int start, end;
    bool started = false;
    Y[row].clear();

    for (int i = 1; i <= m; i++) {
        if (field[row][i]) {
            if (started) {
                end++;
            } else {
                started = true;
                start = end = i;
            }
        } else {
            if (started) {
                Y[row].insert(st(start, end));
                started = false;
            }
        }
    }

    if (started) {
        Y[row].insert(st(start, end));
    }
}

set <st> :: iterator get_segm(int pos, set <st>& Set) {
    set <st> :: iterator it = Set.upper_bound(st(pos, INF));

    if (it == Set.begin())
        return Set.end();

    it--;

    if (it -> a <= pos && pos <= it -> b)
        return it;

    return Set.end();
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    
    scanf("%d%d%d", &n, &m, &q);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &x);
            field[i][j] = x;
        }
    }

    for (int i = 1; i <= n; i++) {
        build_y(i);
    }
    
    for (int j = 1; j <= m; j++) {
        build_x(j);
    }
     
    while (q--) {
        scanf("%d%d%d", &t, &x, &y);

        if (t == 1) {
            field[x][y] ^= true;

            build_x(y);
            build_y(x);
        } else {
            set <st> :: iterator it_x = get_segm(x, X[y]);
            set <st> :: iterator it_y = get_segm(y, Y[x]);

            if (it_x == X[y].end() || it_y == Y[x].end()) {
                puts("0");
            } else {
                int w_left  = INF;
                int w_right = INF;
                int res = 0;

                for (int i = x; i <= n; i++) {
                    it_y = get_segm(y, Y[i]);
                    
                    if (it_y == Y[i].end())
                        break;

                    w_left  = min(w_left,  y - it_y -> a + 1);
                    w_right = min(w_right, it_y -> b - y + 1);

                    res = max(res, (w_left + w_right - 1) * (i - x + 1));
                }

                w_left  = INF;
                w_right = INF;

                for (int i = x; i > 0; i--) {
                    it_y = get_segm(y, Y[i]);
                    
                    if (it_y == Y[i].end())
                        break;

                    w_left  = min(w_left,  y - it_y -> a + 1);
                    w_right = min(w_right, it_y -> b - y + 1);

                    res = max(res, (w_left + w_right - 1) * (x - i + 1));
                }

                int h_top = INF;
                int h_bot = INF;

                for (int j = y; j <= m; j++) {
                    it_x = get_segm(x, X[j]);
                    
                    if (it_x == X[j].end())
                        break;

                    h_top = min(h_top, x - it_x -> a + 1);
                    h_bot = min(h_bot, it_x -> b - x + 1);

                    res = max(res, (h_top + h_bot - 1) * (j - y + 1));
                }
                
                h_top = INF;
                h_bot = INF;
                
                for (int j = y; j > 0; j--) {
                    it_x = get_segm(x, X[j]);
                    
                    if (it_x == X[j].end())
                        break;

                    h_top = min(h_top, x - it_x -> a + 1);
                    h_bot = min(h_bot, it_x -> b - x + 1);

                    res = max(res, (h_top + h_bot - 1) * (y - j + 1));
                }
                
                printf("%d\n", res);
            }
        }
    }

    return 0;
}
