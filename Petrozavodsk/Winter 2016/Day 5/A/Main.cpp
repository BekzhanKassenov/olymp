/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

#ifdef Local
# define I64 "%I64d"
#else
# define I64 "%Ld"
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 1000010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;
int a[MAXN];
long long b[MAXN], c[MAXN];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    while (scanf("%d%d", &n, &m) == 2) {
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }

        c[0] = 0;
        int ptr = 1;
        long long sum = 0;
        while (ptr <= n) {
            sum += a[ptr];

            if (0 <= sum && sum <= m) {
                c[ptr] = sum;
            } else {
                break;
            }

            ptr++;
        }

        while (ptr <= n) {
            int optr = ptr;

            sum = 0;
            //long long osum = sum;

            long long maxSum = 0, minSum = 0;
            long long prevMax = 0, prevMin = 0;

            while (ptr <= n && 0 <= maxSum - minSum && maxSum - minSum <= m && maxSum <= m) {
                ptr++;
                if (ptr <= n) {
                    sum += a[ptr];
                    
                    //cerr << "SUM " << ptr << ' ' << sum << endl;

                    prevMax = maxSum;
                    prevMin = minSum;

                    maxSum = max(maxSum, sum);
                    minSum = min(minSum, sum);
                }
            }

            if (ptr == n + 1 && 0 <= maxSum - minSum && maxSum - minSum <= m && maxSum <= m) {
                prevMin = min(prevMin, minSum);
            }

            //cerr << prevMin << ' ' << minSum << endl;

            if (minSum < 0) {
                c[optr] = -prevMin;
            } else {
                c[optr] = 0;
            }

            for (int j = optr + 1; j < ptr; j++) {
                c[j] = c[j - 1] + a[j];
            }
        }

        /*
        for (int i = 1; i <= n; i++) {
            cerr << c[i] << ' ' ;
        }
        cerr << endl;
        */
        for (int i = 1; i <= n; i++) {
            b[i] = c[i] - c[i - 1] - a[i];

            printf(I64 " " , b[i]);
        }
        puts("");
    }
    
    return 0;
}
