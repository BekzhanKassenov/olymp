/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "explicit"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int N = 10;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

bool a[N];
int x;
bool res;

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &x);
        a[i] = x;
    }

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            res ^= (a[i] || a[j]);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                res ^= (a[i] || a[j] || a[k]);
            }
        }
    }

    printf("%d\n", (int)res);

    return 0;
}
