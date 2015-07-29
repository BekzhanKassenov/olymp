#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef unsigned long long ull;

struct BigInt {
    vector <int> dig;

    BigInt() {
        trim();
    }

    BigInt(int n) {
        while (n) {
            dig.push_back(n % 10);
            n /= 10;
        }

        trim();
    }

    BigInt(const vector <int>& vec) : dig(vec) { }

    void trim() {
        while (!dig.empty() && dig.back() == 0)
            dig.pop_back();

        if (dig.empty())
            dig.push_back(0);
    }

    BigInt operator + (const BigInt& b) const {
        vector <int> res;
        int carry = 0;

        for (size_t i = 0; i < max(b.dig.size(), dig.size()); i++) {
            if (i < b.dig.size())
                carry += b.dig[i];

            if (i < dig.size())
                carry += dig[i];

            res.push_back(carry % 10);
            carry /= 10;
        }

        while (carry) {
            res.push_back(carry % 10);
            carry /= 10;
        }

        return BigInt(res);
    }

    static BigInt pow2(int power) {
        BigInt res(1);

        for (int i = 0; i < power; i++) {
            res = res + res;
        }

        return res;
    }

    void print() {
        for (int i = dig.size() - 1; i >= 0; i--)
            printf("%d", dig[i]);
        puts("");
    }
};

ull C(ull n, ull k) {
    if (k == 0)
        return 1;

    if (k < n - k)
        k = n - k;

    ull res = 1;
    for (ull i = k + 1; i <= n; i++)
        res *= i;

    for (ull i = 2ull; i <= n - k; i++)
        res /= i;

    return res;
}

ull n;
ull pos[3];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%I64d", &n);

    ull num = 0;
    
    pos[0] = 2;
    pos[1] = 1;
    pos[2] = 0;

    for (int idx = 0; idx < 3; idx++) {
        for (ull i = 2 - idx; ; i++) {
            ull choose = C(i, 2 - idx);
            pos[idx] = i;

            //printf("IDX: %d, I: %I64d, C(%I64d, %d)=%I64d\n", idx, i, i, 2 - idx, choose);

            if (num + choose >= n)
                break;

            num += choose;
        }
    }

    BigInt res;

    for (int i = 0; i < 3; i++)
        res = res + BigInt::pow2(pos[i]);

    res.print();

    return 0;
}
