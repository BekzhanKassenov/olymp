#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 310;
const int BASE = 10;

struct BigInt {
    vector <int> dig;

    BigInt() {
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

        if (dig.empty()) {
            dig.push_back(0);
        }
    }

    void print() {
        for (int i = dig.size() - 1; i >= 0; i--) {
            printf("%d", dig[i]);
        }
    }

    void println() {
        print();
        puts("");
    }
};

BigInt& operator += (BigInt& lhs, const BigInt& rhs) {
    int carry = 0;
    for (size_t i = 0; i < lhs.dig.size(); i++) {
        carry += lhs.dig[i];
        if (i < rhs.dig.size()) {
            carry += rhs.dig[i];
        }

        lhs.dig[i] = carry % BASE;
        carry /= 10;
    }

    for (size_t i = lhs.dig.size(); i < rhs.dig.size(); i++) {
        carry += rhs.dig[i];
        lhs.dig.push_back(carry % 10);
        carry /= 10;
    }

    while (carry > 0) {
        lhs.dig.push_back(carry % 10);
        carry /= 10;
    }

    return lhs;
}

BigInt operator * (const BigInt& lhs, const BigInt& rhs) {
    BigInt result;
    result.dig.resize(lhs.dig.size() + rhs.dig.size());

    for (size_t i = 0; i < lhs.dig.size(); i++) {
        long long carry = 0;
        for (size_t j = 0; j < rhs.dig.size() || carry > 0; j++) {
            carry += result.dig[i + j];

            if (j < rhs.dig.size()) {
                carry += lhs.dig[i] * rhs.dig[j];
            }

            result.dig[i + j] = carry % 10;
            carry /= 10;
        }
    }

    result.trim();
    return result;
}

int n;
vector <int> g[MAXN];
BigInt dp[MAXN];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    return 0;
}
