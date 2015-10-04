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

const double EPS = 1e-18;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const ull D = 100000;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int Q;
long double a, b, c;
/*
struct BigInt {
    vector <int> dig;

    void trim() {
        while (!dig.empty() && dig.back() == 0) {
            dig.pop_back();
        }

        if (dig.empty()) {
            dig.push_back(0);
        }
    }

    BigInt(ull n) {
        while (n > 0) {
            dig.push_back(n % 10);
            n /= 10;
        }

        trim();
    }
    
    BigInt& operator += (const BigInt& p) const {
        int carry = 0;
        for (size_t i = 0; i < dig.size(); i++) {
            carry += dig[i];

            if (ca
        }
    }
};
*/

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    cin >> Q;

    while (Q--) {
        cin >> a >> b >> c;

        a *= D;
        b *= D;
        c *= D;

        if ((a * b + b * c + a * c) * D - a * b * c < -EPS) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
