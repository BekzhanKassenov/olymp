/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define hash asdasdas

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int BASE = 9;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int fact(int n) {
    if (n == 0) {
        return 1;
    }

    return n * fact(n - 1);
}

int n;
vector <int> a;
set <vector <int> > used;
vector <int> masks;

bool has(int mask, int bit) {
    return (mask & (1 << bit)) > 0;
}

bool ok(int mask) {
    for (int i = 0; i < n; i++) {
        if (has(mask, i)) {
            if (i + 1 >= n) {
                return false;
            }

            if (has(mask, i + 1)) {
                return false;
            }

            if (i > 0 && has(mask, i - 1)) {
                return false;
            }
        }
    }

    return true;
}


int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d", &n);

    if (n == 2) {
        puts("1 2");
        puts("2 1");

        return 0;
    }

    for (int mask = 1; mask < (1 << n); mask++) {
        if (ok(mask)) {
            masks.push_back(mask);
        }
    }
   
    a.resize(n);

    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }

    int d = fact(n);

    while (d--) {
        assert(!used.count(a));
        used.insert(a);

        for (int i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
        puts("");

        for (int mask: masks) {
            for (int i = 0; i < n; i++) {
                if (has(mask, i)) {
                    swap(a[i], a[i + 1]);
                }
            }

            if (used.count(a)) {
                for (int i = 0; i < n; i++) {
                   if (has(mask, i)) {
                        swap(a[i], a[i + 1]);
                    }
                }
            } else {
                break;
            }   
        }
    }

    return 0;
}
