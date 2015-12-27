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

class DoubleOrOneEasy {
    int getMin(int k, int coeff) {
        int ans = 0;

        while (k--) {
            if (coeff & 1) {
                ans++;
                coeff--;
            }
        }
    }
public:
     int minimalSteps(int a, int b, int newA, int newB) {
        if (newA < a || newB < b) {
            return -1;
        }

        int ans = -1;
        int steps = 0;
        while (a <= newA && b <= newB) {
            if (newA - a == newB - b) {
                int res = steps + getMin(steps, newA - a);
                if (ans == -1 || res < ans) {
                    ans = res;
                }
            }

            steps++;
            a *= 2, b *= 2;
        }

        return ans;
     }
};