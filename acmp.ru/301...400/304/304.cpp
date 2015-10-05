#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

struct BigInt {
    vector <int> dig;

    BigInt(long long val = 0) {
        while (val > 0) {
            dig.push_back(val % 10);
            val /= 10;
        }

        trim();
    }

    BigInt(const vector <int>& vec) {
        dig = vec;
        trim();
    }

    void trim() {
        while (!dig.empty() && dig.back() == 0) {
            dig.pop_back();
        }

        if (dig.empty()) {
            dig.push_back(0);
        }
    }

    void print() {
        for (int i = dig.size() - 1; i >= 0; i--) {
            printf("%d", dig[i]);
        }
    }
};

BigInt operator * (const BigInt& lhs, const BigInt& rhs) {
    const vector <int>& l = lhs.dig;
    const vector <int>& r = rhs.dig;

    vector <int> result(l.size() + r.size());

    for (size_t i = 0; i < l.size(); i++) {
        long long carry = 0;

        for (size_t j = 0; j < r.size() || carry > 0; j++) {
            carry += result[i + j];

            if (j < r.size()) {
                carry += l[i] * r[j];
            }

            result[i + j] = carry % 10;
            carry /= 10;
        }
    }

    BigInt ans(result);
    ans.trim();

    return ans;
}

BigInt ans(1ll);

long long C(int n, int k) {
    long long ans = 1;

    if (k > n - k) {
        k = n - k;
    }

    int j = 1;
    for (int i = n - k + 1; i <= n; i++) {
        ans *= i;

        while (j <= k && ans % j == 0) {
            ans /= j;
            j++;
        }
    }

    return ans;
}

long long power(long long base, int p) {
    long long result = 1;
    
    while (p > 0) {
        if (p & 1) {
            result *= base;
        }

        base *= base;
        p >>= 1;
    }

    return result;
}

long long solve(int a, int b, int lim) {
    long long ans = 1;

    if (a > lim || b > lim) {
        if (abs(a - b) != 2) {
            return 0;
        }
        
        ans = C(lim + lim - 2, lim - 1);

        ans *= power(2, min(a, b) - lim + 1);
    } else {
        ans = C(a + b - 1, max(a, b) - 1);
    }

    return ans;
}

int n, a, b;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d:%d", &a, &b);

        int lim = 25;
        if (i == 5) {
            lim = 15;
        }

        BigInt mul(solve(a, b, lim));
        ans = ans * mul;
    }

    ans.print();
    puts("");

    return 0;
}
