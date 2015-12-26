/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "stars"
#define _y1 asdas

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 150;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
long long t[MAXN][MAXN][MAXN];

long long get(int xx, int yy, int zz) {
    long long result = 0;
    for (int x = xx; x >= 0; x = (x & (x + 1)) - 1) {
        for (int y = yy; y >= 0; y = (y & (y + 1)) - 1) {
            for (int z = zz; z >= 0; z = (z & (z + 1)) - 1) {
                result += t[x][y][z];
            }
        }
    }

    return result;
}

long long get(int _x1, int _y1, int _z1, int _x2, int _y2, int _z2) {
    long long sum = get(_x2, _y2, _z2);
    
    sum -= get(_x1 - 1, _y2, _z2);
    sum -= get(_x2, _y1 - 1, _z2);
    sum -= get(_x2, _y2, _z1 - 1);

    sum += get(_x1 - 1, _y1 - 1, _z2);
    sum += get(_x1 - 1, _y2, _z1 - 1);
    sum += get(_x2, _y1 - 1, _z1 - 1);

    sum -= get(_x1 - 1, _y1 - 1, _z1 - 1);

    return sum;
}

void update(int xx, int yy, int zz, int val) {
    for (int x = xx; x < n; x |= x + 1) {
        for (int y = yy; y < n; y |= y + 1) {
            for (int z = zz; z < n; z |= z + 1) {
                t[x][y][z] += val;
            }
        }
    }
}

int _x1, _y1, _z1, _x2, _y2, _z2;
int type, val;

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    scanf("%d", &n);

    while (scanf("%d", &type) != -1 && type != 3) {
        if (type == 1) {
            scanf("%d%d%d%d", &_x1, &_y1, &_z1, &val);

            update(_x1, _y1, _z1, val);
        } else if (type == 2) {
            scanf("%d%d%d%d%d%d", &_x1, &_y1, &_z1, &_x2, &_y2, &_z2);

            printf("%I64d\n", get(_x1, _y1, _z1, _x2, _y2, _z2));
        }
    }

    return 0;
}
