/****************************************
**          Solution by NU #1          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define to_string Algiz_lal

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

template <typename T>
inline T sqr(T n) {
    return n * n;
}

string to_string(long long a) {
    if (a == 0) {
        return "0";
    }

    string result;

    while (a > 0) {
        result.append(1, a % 10 + '0');
        a /= 10;
    }

    return result;
}

long long to_ll(const string& s) {
    long long result = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        result *= 10;
        result += s[i] - '0';
    }

    return result;
}

long long f(long long n) {
    if (n == 0) {
        return 0;
    }

    long long mul = 1;

    while (n > 0) {
        mul *= n % 10;
        n /= 10;
    }

    return mul;
}

void make(string& s, int pos) {
    if (s[pos] == '0') {
        return;
    }

    s[pos]--;
    for (int i = pos - 1; i >= 0; i--) {
        s[i] = '9';
    }
}

long long solve(long long a, long long b) {
    string sb = to_string(b);

    long long ans = b;
    for (size_t i = 0; i < sb.size(); i++) {
        string cp = sb;
        make(cp, i);

        long long num = to_ll(cp);
        if (a <= num && num <= b && f(num) > f(ans)) {
            ans = num;
        }
    }

    return ans;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    long long a, b;
    scanf(I64 I64, &a, &b);

    long long ans = solve(a, b);
    if (f(b) > f(ans)) {
        ans = b;
    }

    if (f(a) > f(ans)) {
        ans = a;
    }

    printf(I64 "\n", ans);

    return 0;
}
