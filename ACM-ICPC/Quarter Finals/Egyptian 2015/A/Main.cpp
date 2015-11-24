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

int T;
int n;

void unpack(int n, vector <int>& vec) {
    while (n > 0) {
        vec.push_back(n % 10);
        n /= 10;
    }
}

int pack(const vector <int>& vec) {
    int result = 0;
    for (int digit: vec) {
        result *= 10;
        result += digit;
    }

    return result;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n);

        vector <int> vec;
        unpack(n, vec);

        sort(all(vec));

        int pos = 1;
        int cnt = 0;
        do {
            if (pack(vec) < n) {
                pos++;
            }

            cnt++;
        } while (next_permutation(all(vec)));

        if (pos == cnt) {
            puts("0.000000000");
        } else {
            double S = 1, prob = 1;
            double alpha = 1.0 / cnt;

            for (int i = pos + 1; i <= cnt; i++) {
                prob = S * alpha;
                S += prob;
            }

            printf("%.9lf\n", prob);
        }
    }
    
    return 0;
}
