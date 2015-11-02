/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File ""

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

struct BigInt {
    vector <int> dig;

    BigInt() {
        trim();
    }

    BigInt(char s[]) {
        for (int i = 0; s[i]; i++) {
            dig.push_back(s[i] - '0');
        }

        reverse(all(dig));
        trim();
    }

    BigInt(int n) {
        while (n > 0) {
            dig.push_back(n % 10);
            n /= 10;
        }

        trim();
    }

    void trim() {
        while (!dig.empty() && dig.back() == 0) {
            dig.pop_back();
        }
    }

    void operator += (const BigInt& other) {
        int carry = 0;

        for (size_t i = 0; i < dig.size(); i++) {
            carry += dig[i];

            if (i < other.dig.size()) {
                carry += other.dig[i];
            }

            dig[i] = carry % 10;
            carry /= 10;
        }
    }
};

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    return 0;
}
