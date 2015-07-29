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
const int MAXN = 51;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

char grid[MAXN][MAXN + 1];
char temp[10];
int h, m;

void prepare_grid() {
    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXN; j++)
            grid[i][j] = ' ';

    for (int i = 0; i < MAXN; i++) {
        if (i % 10 == 0) {
            grid[i][0] = grid[0][i] = '@';
            grid[i][50] = grid[50][i] = '@';
        } else {
            grid[i][0] = grid[0][i] = 'X';  
            grid[i][50] = grid[50][i] = 'X';
        }
    }

    grid[25][25] = '*';
    
    grid[2][24] = '1';
    grid[2][26] = '2';

    grid[25][48] = '3';
    
    grid[48][25] = '6';
    
    grid[25][2] = '9';
}

char get_char(int x0, int y0,
              int x1, int y1,
              int x2, int y2) {

    for (int i = 0; i < 2; i++) {
        if (x0 == x1 - 1 && y0 == y1 &&
            x2 == x1 + 1 && y2 == y1)
            return '-';

        if (x0 == x1 && y0 == y1 - 1 &&
            x2 == x1 && y2 == y1 + 1)
            return '|';

        if (x0 == x1 - 1 && y0 == y1 - 1 &&
            x2 == x1 + 1 && y2 == y1 + 1)
            return '\\';

        if (x0 == x1 - 1 && y0 == y1 + 1 &&
            x2 == x1 + 1 && y2 == y1 - 1)
            return '/';

        swap(x0, x2);
        swap(y0, y2);
    }

    return 'o';
}

void get_coord(int& xx, int& yy, int i, double angle) {
    if (angle <= PI / 4) {
        yy = -i;
        xx = int(i * tan(angle) + .5);
    } else if (angle <= PI / 2) {
        xx = i;
        yy = -int(i * tan(PI / 2 - angle) + .5);
    } else if (angle <= 3 * PI / 4) {
        xx = i;
        yy = int(i * tan(angle - PI / 2) + .5);
    } else if (angle <= PI) {
        yy = i;
        xx = int(i * tan(PI - angle) + .5);
    } else if (angle <= 5 * PI / 4) {
        yy = i;
        xx = -int(i * tan(angle - PI) + .5);
    } else if (angle <= 3 * PI / 2) {
        xx = -i;
        yy = int(i * tan(3 * PI / 2 - angle) + .5);
    } else if (angle <= 7 * PI / 4) {
        xx = -i;
        yy = -int(i * tan(angle - 3 * PI / 2) + .5);
    } else {
        yy = -i;
        xx = -int(i * tan(-angle) + .5);
    }
}

void build_line(double angle, int len) {
    vector <int> x, y;
    x.push_back(25);
    y.push_back(25);

    for (int i = 1; i < 26; i++) {
        int yy;
        int xx;

        get_coord(xx, yy, i, angle);

        x.push_back(25 + xx);
        y.push_back(25 + yy);
    }

    for (size_t i = 1; i + 1 < x.size(); i++) {
        char c = get_char(x[i - 1], y[i - 1],
                          x[i], y[i],
                          x[i + 1], y[i + 1]);
    
        if (sqr(x[i] - 25) + sqr(y[i] - 25) <= sqr(len))
            grid[y[i]][x[i]] = c;
        else
            break;

        cerr << sqr(x[i] - 25) + sqr(y[i] - 25) << ' ' << sqr(len) << endl;
    }
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    while (gets(temp) && strcmp(temp, "END") != 0) {
        sscanf(temp, "%d:%d", &h, &m);

        if (h >= 12)
            h -= 12;

        prepare_grid();
        build_line(2 * PI * (h * 60.0 + m) / (12.0 * 60.0), 15);
        build_line(2 * PI * (m / 60.0), 21);

        for (int i = 0; i < MAXN; i++)
            puts(grid[i]);

        puts("");
    }

    puts("");
    
    return 0;
}
