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

long long t, a, b;
long long ans;

bool check(long long n, long long a) {
    while (n % a == 0) {
        n /= a;
    }

    return n == 1;
}

vector <long long> convert(long long num, long long base) {
    vector <long long> result;

    while (num > 0) {
        result.push_back(num % base);
        num /= base;
    }

    return result;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%I64d%I64d%I64d", &t, &a, &b);

    if (t != 1) {
        if (a == b) {
            ans++;
        }

        if (a != 1 && convert(a, t) == convert(b, a)) {
           ans++;
        }
    } else {
        if (a == 1) {
            if (b == 1) {
                puts("inf");
                return 0;
            }

            ans = 0;
        } else {
            vector <long long> temp(convert(b, a));

            long long sum = 0;
            for (size_t i = 0; i < temp.size(); i++) {
                sum += temp[i];
            }

            if (sum == a) {
                ans = 1;
            }

            if (b >= a && check(b, a)) {
                ans++;
            }
        }
    }

    printf("%I64d\n", ans);
    
    return 0;
}
