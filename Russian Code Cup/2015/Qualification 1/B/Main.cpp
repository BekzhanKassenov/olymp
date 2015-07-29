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
const int MAXN = 210;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

char buf[MAXN];
int BASE;

struct BigInt {
    vector <int> dig;
    
    void read() {
        dig.clear();
        gets(buf);
        for (int i = 0; buf[i]; i++) {
            dig.push_back(buf[i] - '0');
        }

        reverse(all(dig));
    }

    void trim() {
        while (!dig.empty() && dig.back() == 0) {
            dig.pop_back();
        }

        if (dig.empty()) {
            dig.push_back(0);
        }
    }

    void print() const {
        for (int i = dig.size() - 1; i >= 0; i--) {
            printf("%d", dig[i]);
        }
        puts("");
    }
};

BigInt operator * (const BigInt& l, const BigInt& r) {
    BigInt result;
    result.dig.resize(l.dig.size() + r.dig.size());

    for (size_t i = 0; i < l.dig.size(); i++) {
        int carry = 0;
        for (size_t j = 0; j < r.dig.size() || carry > 0; j++) {
            carry += result.dig[i + j];

            if (j < r.dig.size())
                carry += l.dig[i] * r.dig[j];
            
            result.dig[i + j] = carry % BASE;
            carry /= BASE;
        }
    }

    result.trim();
    return result;
}

bool operator == (const BigInt& l, const BigInt& r) {
    if (l.dig.size() != r.dig.size()) {
        return false;
    }

    for (size_t i = 0; i < l.dig.size(); i++) {
        if (l.dig[i] != r.dig[i]) {
            return false;
        }
    }

    return true;
}

bool operator != (const BigInt& l, const BigInt& r) {
    return !(l == r);
}

int T;
BigInt a, b, c;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d\n", &T);
    BASE = 100;

    while (T--) {
        a.read();
        b.read();
        c.read();

        if (a * b != c) {
            puts("Finite");
        } else {
            puts("Infinity");
        }
    }

    return 0;
}
