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

int n, k;
ll fact, temp, sum;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    cin >> n >> k;

    if (k == 0) {
        sum = n + 1;
    } else {
        fact = 1;
        sum = 1;

        for (int i = 1; i <= n; i++) {
            temp = 1;
            fact *= i;

            if (fact % 10 == 0)
                break;

            for (int j = 0; j < k; j++)
                temp *= fact;

            sum += temp;
        }
    }

    while (sum % 10 == 0)
        sum /= 10;

    cout << sum % 10;

    return 0;
}
