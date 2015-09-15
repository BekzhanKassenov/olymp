/****************************************
**     Solution by Bekzhan Kassenov    **
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
const int LIM = 1000 * 1000 * 10;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m, k;
map <int, int> f;

int grundy(int n) {
    if (f.count(n)) {
        return f[n];
    }

    if (n <= k) {
        return 0;
    }

    vector <int> temp;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int x = 0, cnt = 0;

            if (i >= k) {
                x = i, cnt = n / i;
                if (cnt & 1) {
                    temp.push_back(grundy(x));
                } else {
                    temp.push_back(0);
                }
            }

            if (n / i >= k) {
                x = n / i, cnt = i;
                if (cnt & 1) {
                    temp.push_back(grundy(x));
                } else {
                    temp.push_back(0);
                }
            }
        }
    }

    if (k == 1 && n > 1) {
        if (n & 1) {
            temp.push_back(grundy(1));
        } else {
            temp.push_back(0);
        }
    }

    sort(all(temp));
    temp.resize(unique(all(temp)) - temp.begin());

    f[n] = -1;

    for (int i = 0; ; i++) {
        if (!binary_search(all(temp), i)) {
            f[n] = i;
            break;
        }
    }

//    printf("f[%d]=%d\n", n, f[n]);

    return f[n];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d%d", &n, &m, &k);

    int x = 0;

    if (n & 1) {
        x = grundy(m);
    }

    if (x != 0) {
        puts("Timur");
    } else {
        puts("Marsel");
    }
    
    return 0;
}
