/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "party"

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

vector <int> numbers;

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    /*
    for (int i = 1; i < (1 << 9); i++) {
        long long mul = 1;

        for (int j = 0; j < 9; j++) {
            if (i & (1 << j))
                mul *= j + 1;
        }

        long long k = sqrt(mul);

        if (k * k == mul)
            printf("%d\n", i);
    }
    */
    int tot = 0;
    for (int i = 1; i < 1000000000; i++) {
        int k = i, sum = 1;
        while (k > 0) {
            if (k%10 == 0)
            {
                sum = 0;
                break;
            }
            sum *= (k%10);
            k /= 10;
        }
        int z = (int)sqrt(sum);
        if (z*z == sum && sum){
        tot++;
        }
    }
    cout << tot;
    return 0;
}
