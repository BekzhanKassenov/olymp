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
const int MAXN = 1010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, p[MAXN], ans[MAXN];
int a[MAXN];

int main() {
    ifstream input("root.in");
    ifstream answer("root.out");

    input >> n;

    for (int i = 1; i <= n; i++) {
        input >> p[i];
    }

    for (int i = 1; i <= n; i++) {
        answer >> ans[i];
    }

    for (int i = 1; i <= n; i++) {
        a[i] = ans[ans[i]];
    }

    for (int i = 1; i <= n; i++) {
        if (a[i] != p[i]) {
            for (int j = 1; j <= n; j++) {
                cerr << a[i] << ' ';
            }
            cerr << endl;
            return 1;
        }
    }

    return 0;
}
