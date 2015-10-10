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
const int INF = 2000 * 1000 * 1000;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int MOD;

struct Mat {
    int a[4][4];

    Mat() {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (i == j) {
                    a[i][j] = 1;
                } else {
                    a[i][j] = 0;
                }
            }
        }
    }

    Mat(int k) {
        memset(a, 0, sizeof a);

        a[0][1] = a[0][2] = 1;
        
        a[1][0] = k;
        a[1][3] = 1;
        
        a[2][0] = 1;
        a[2][1] = k;
        
        a[3][2] = 1;
    }

    bool operator == (const Mat& m) const {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (a[i][j] != m.a[i][j]) {
                    return false;
                }
            }
        }

        return true;
    }
};

Mat operator * (const Mat& lhs, const Mat& rhs) {
    Mat result;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result.a[i][j] = 0;

            for (int k = 0; k < 4; k++) {
                result.a[i][j] += lhs.a[i][k] * rhs.a[k][j];
                result.a[i][j] %= MOD;
            }
        }
    }

    return result;
}

Mat binpow(Mat a, int p) {
    Mat result;

    while (p > 0) {
        if (p & 1) {
            result = result * a;
        }

        p >>= 1;
        a = a * a;
    }

    return result;
}

int binpow(int a, int p) {
    int result = 1;

    while (p > 0) {
        if (p & 1) {
            result = (result * a) % MOD;
        }

        p >>= 1;
        a = (a * a) % MOD;
    }

    return result;
}

int T, X;
int ax, bx, cx, kx, nx;
int ay, by, cy, ky, ny;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &MOD);

        scanf("%d%d%d%d%d", &ax, &bx, &cx, &kx, &nx);
        scanf("%d%d%d%d%d", &ay, &by, &cy, &ky, &ny);
        
        scanf("%d", &X);

        Mat m1(kx);
        Mat m2(ky);

        m2 = binpow(m2, ny - 1);
        m1 = binpow(m1, nx - 1);
        
        if (ny == 1) {
            printf("%d\n", ay);
        } else if (m2.a[0][3] == 0) {
            int Y = (m2.a[0][0] * ay % MOD + m2.a[0][1] * by % MOD + m2.a[0][2] * cy % MOD) % MOD;
            printf("%d\n", Y);
        } else if (m1.a[0][3] == 0 || nx == 1) {
            puts("UNKNOWN");
        } else {
            int inv = binpow(m1.a[0][3], MOD - 2);
            int h0 = (ax * m1.a[0][0] % MOD + bx * m1.a[0][1] % MOD + cx * m1.a[0][2] % MOD) % MOD;
            h0 = (X - h0 + MOD) % MOD;
            h0 = (h0 * inv) % MOD;

            int Y = (m2.a[0][0] * ay % MOD + m2.a[0][1] * by % MOD + m2.a[0][2] * cy % MOD + m2.a[0][3] * h0 % MOD) % MOD;

            printf("%d\n", Y);

        }
    }
    
    return 0;
}
                