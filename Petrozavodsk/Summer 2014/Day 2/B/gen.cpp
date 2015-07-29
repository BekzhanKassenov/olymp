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
                     
template <typename T>
inline T sqr(T n) {
    return n * n;
}

bool prime(int n) {
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;

    return true;
}

int main() {
#ifdef Local
    freopen("in", "w", stdout);
#endif
    srand(time(NULL));

    int n = 5;

    for (int i = 0; i < n; i++) {
        cout << rand() % 100;
    }

    cout << endl;

    int k = 2 + rand() % 100;

    while (!prime(k)) 
        k++;

    cout << k << endl;

    return 0;
}
