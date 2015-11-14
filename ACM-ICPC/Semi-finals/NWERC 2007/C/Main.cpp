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

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int T;
long long n;
long long ansa, ansb, ans, ansarea;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &T);

    while (T--) {
        scanf("%I64d", &n);

        ans = -1, ansa = -1, ansb = -1, ansarea = -1;
        n = (n + 4) / 5;

        for (long long i = 1; i * i <= n; i++) {
            long long a = 44 * i + 4, b = 10 * ((n + i - 1) / i) + 2;
            
            long long val = abs(a - b);
            long long area = a * b;
            if (ans == -1 || area < ansarea || (area == ansarea && val < ans)) {
                ans = val;
                ansa = a;
                ansb = b;
                ansarea = area;
            }

            a = 44 * ((n + i - 1) / i) + 4, b = 10 * i + 2;
            val = abs(a - b);
            area = a * b;
            if (ans == -1 || area < ansarea || (area == ansarea && val < ans)) {
                ans = val;
                ansa = a;
                ansb = b;
                ansarea = area;
            }
        }

        printf("%I64d X %I64d = %I64d\n", max(ansa, ansb), min(ansa, ansb), ansa * ansb);
    }
    
    return 0;
}
