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

const double EPS = 1e-5;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;
vector <valarray <double> > vec;

void norm(valarray <double>& a) {
    double len = 0;
    for (double x: a) {
        len += sqr(x);
    }

    len = sqrt(len);
    if (abs(len) > EPS)
        a /= len;
}

int posMax(int start, int col) {
    int res = -1;
    for (int i = start; i < n; i++) {
        if (abs(vec[i][col]) > EPS && (res == -1 || abs(vec[res][col]) < abs(vec[i][col]))) {
            res = i;
        }
    }

    return res;
}

void REF(vector <valarray <double> >& vec) {
    int col = 0;
    for (int i = 0; i < n; i++) {
        norm(vec[i]);
        while (col < m && posMax(i, col) == -1) {
            col++;
        }

        if (col == m) {
            break;
        }

        int pos = posMax(i, col);
        vec[i].swap(vec[pos]);

        for (int j = i + 1; j < n; j++) {
            double c = vec[j][col] / vec[i][col];
            vec[j] -= c * vec[i];
            norm(vec[j]);
        }

        col++;
    }
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    vec.resize(n, valarray <double> (m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%lf", &vec[i][j]);
        }
    }

    REF(vec);

#ifdef Local
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << vec[i][j] << ' ';
        }
        cout << endl;
    }
#endif

    int ans = 0;
    for (int i = 0; i < n; i++) {
        bool ok = false;
        for (int j = 0; j < m; j++) {
            if (abs(vec[i][j]) > EPS) {
                ok = true;
            }
        }

        ans += ok;
    }

    printf("%d\n", ans);

    return 0;
}
