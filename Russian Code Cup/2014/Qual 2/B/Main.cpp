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

int T, n, m, kk, h, w;
int used[3][3];
ll sum;
bool flag;

void fill_arr(int x, int y) {
    used[x][y] = 1;

    for (int i = 0; i < w; i++)
        if (!used[x][i])
            used[x][i] = 2;

    for (int i = 0; i < h; i++)
        if (!used[i][y])
            used[i][y] = 2;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
                                
    scanf("%d", &T);

    while (T --> 0) {
        scanf("%d%d%d", &n, &m, &kk);

        flag = false;

        if (n * 1ll * m >= kk) {
            h = min(3, n);
            w = min(3, m);

            for (int i = 0; i < h * w && !flag; i++) {
                for (int j = i + 1; j < h * w && !flag; j++) {
                    for (int k = j + 1; k < h * w && !flag; k++) {
                        memset(used, 0, sizeof used);

                        fill_arr(i / w, i % w);
                        fill_arr(j / w, j % w);
                        fill_arr(k / w, k % w);

                        sum = 0;

                        for (int z = 0; z < h; z++)
                            for (int x = 0; x < w; x++)
                                if (used[z][x] == 2)
                                    sum++;

                        for (int z = 0; z < h; z++)
                            if (z == i / w || z == j / w || z == k / w)
                                sum += m - w;
                        
                        for (int z = 0; z < w; z++)
                            if (z == i % w || z == j % w || z == k % w) 
                                sum += n - h;
                        
                        if (sum == kk) {
                            printf("%d %d %d %d %d %d\n", i / w + 1, i % w + 1,
                                                          j / w + 1, j % w + 1,
                                                          k / w + 1, k % w + 1);
                            flag = true;
                        }
                    }
                }
            }
        }

        if (!flag)
            puts("IMPOSSIBLE");
    }

    return 0;
}
