#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

struct BigInt {
    vector <int> digits;

    BigInt() {
        trim();
    }

    BigInt(int n) {
        while (n > 0) {
            digits.push_back(n % 10);
            n /= 10;
        }

        trim();
    }

    void trim() {
        while (!digits.empty() && digits.back() == 0) {
            digits.pop_back();
        }

        if (digits.empty()) {
            digits.push_back(0);
        }
    }

    void print() {
        for (int i = digits.size() - 1; i >= 0; i--) {
            printf("%d", digits[i]);
        }
    }

    void println() {
        print();
        puts("");
    }
};

BigInt operator * (const BigInt& l, const BigInt& r) {
    BigInt result;
    result.digits.resize(l.digits.size() + r.digits.size());

    for (size_t i = 0; i < l.digits.size(); i++) {
        long long carry = 0;

        for (size_t j = 0; j < r.digits.size() || carry > 0; j++) {
            carry += result.digits[i + j];

            if (j < r.digits.size()) {
                carry += l.digits[i] * r.digits[j];
            }

            result.digits[i + j] = carry % 10;
            carry /= 10;
        }
    }

    result.trim();

    return result;
}

BigInt operator + (BigInt l, const BigInt& r) {
    int carry = 0;
    for (size_t i = 0; i < l.digits.size(); i++) {
        carry += l.digits[i];

        if (i < r.digits.size()) {
            carry += r.digits[i];
        }

        l.digits[i] = carry % 10;
        carry /= 10;
    }

    for (size_t i = l.digits.size(); i < r.digits.size(); i++) {
        carry += r.digits[i];
        l.digits.push_back(carry % 10);
        carry /= 10;
    }

    while (carry > 0) {
        l.digits.push_back(carry % 10);
        carry /= 10;
    }
    
    return l;
}

bool calced[110];
BigInt d[110];
int n;

void calc(int n) {
    if (calced[n]) {
        return;
    }

    calced[n] = true;
    calc(n - 1);
    calc(n - 2);

    d[n] = BigInt(n - 1) * (d[n - 1] + d[n - 2]);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    d[1] = 0;
    d[2] = 1;

    calced[1] = true;
    calced[2] = true;

    scanf("%d", &n);

    calc(n);

    d[n].print();

    return 0;
}
