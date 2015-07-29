#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

#define all(x) (x).begin(), (x).end()

const int BASE = 10;
const int MAXN = 3010;

struct BigInt {
    vector <int> digits;

    BigInt() {
        trim();
    }

    BigInt(char* s) {
        int n = strlen(s);

        for (int i = n - 1; i >= 0; i--) {
            digits.push_back(s[i] - '0');
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

    void print() const {
        int n = digits.size();

        for (int i = n - 1; i >= 0; i--) {
            printf("%d", digits[i]);
        }
    }
};


BigInt& operator += (BigInt& l, const BigInt& r) {
    int carry = 0;

    for (size_t i = 0; i < l.digits.size(); i++) {
        carry += l.digits[i];

        if (i < r.digits.size()) {
            carry += r.digits[i];
        }

        l.digits[i] = carry % BASE;
        carry /= BASE;
    }

    for (size_t i = l.digits.size(); i < r.digits.size(); i++) {
        carry += r.digits[i];
        l.digits.push_back(carry % BASE);
        carry /= BASE;
    }

    while (carry > 0) {
        l.digits.push_back(carry % BASE);
        carry /= BASE;
    }

    l.trim();

    return l;
}

BigInt& operator *= (BigInt& num, int k) {
    long long carry = 0;

    for (size_t i = 0; i < num.digits.size(); i++) {
        carry += num.digits[i] * k;
        num.digits[i] = carry % 10;
        carry /= 10;
    }

    while (carry > 0) {
        num.digits.push_back(carry % 10);
        carry /= 10;
    }

    return num;
}

bool operator < (const BigInt& l, const BigInt& r) {

    if (l.digits.size() != r.digits.size()) {
        return l.digits.size() < r.digits.size();
    }

    int len = l.digits.size();

    for (int i = len - 1; i >= 0; i--) {
        if (l.digits[i] != r.digits[i]) {
            return l.digits[i] < r.digits[i];
        }
    }
    
    return false;
}

bool operator <= (const BigInt& l, const BigInt& r) {
    return !(r < l);
}

char s[MAXN];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    gets(s);

    BigInt num(s);
    BigInt ans;
    BigInt ZERO;

    BigInt cur;
    cur.digits.resize(num.digits.size() / 2 + 1);
    cur.digits.back() = 1;

    BigInt sqrcur;
    sqrcur.digits.resize(2 * cur.digits.size() - 1);
    sqrcur.digits.back() = 1;

    BigInt sqr;

    while (ZERO < cur) {
        BigInt sum = sqr;
        BigInt temp = ans;
        temp *= 2;

        reverse(all(temp.digits));
        
        for (size_t i = 0; i + 1 < cur.digits.size(); i++) {
            temp.digits.push_back(0);
        }

        reverse(all(temp.digits));
        
        sum += temp;

        sum += sqrcur;

        if (sum <= num) {
            sqr = sum;
            ans += cur;
        } else {
            cur.digits.erase(cur.digits.begin());
            sqrcur.digits.erase(sqrcur.digits.begin());
            
            if (!sqrcur.digits.empty()) {
                sqrcur.digits.erase(sqrcur.digits.begin());
            }
        }
    }

    ans.print();
    puts("");
                
    return 0;
}
