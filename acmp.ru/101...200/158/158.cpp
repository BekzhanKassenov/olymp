#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define all(x) (x).begin(), (x).end()

struct BigInt {
    vector <int> nmb;

    static const int BASE = 10;

    BigInt() {
        nmb.push_back(0);
    }

    BigInt(int n) {
        if (n == 0) {
            nmb.push_back(0);
        } else {
            while (n > 0) {
                nmb.push_back(n % BASE);
                n /= BASE;
            }
        }
    }

    void operator *= (int k) {
        long long carry = 0;

        for (size_t i = 0; i < nmb.size(); i++) {
            carry += nmb[i] * k;
            nmb[i] = carry % BASE;
            carry /= BASE;
        }

        while (carry > 0) {
            nmb.push_back(carry % BASE);
            carry /= BASE;
        }

        trim();
    }

    void trim() {
        while (!nmb.empty() && nmb.back() == 0) {
            nmb.pop_back();
        }

        if (nmb.empty()) {
            nmb.push_back(0);
        }
    }

    void print() {
        for (int i = nmb.size() - 1; i >= 0; i--)
            cout << nmb[i];
        cout << endl;   
    }
};

int x, k;
int divs[1000];

void fact(int num, int delta) {
    for (int i = 2; num > 1; i++) {
        while (num % i == 0) {
            divs[i] += delta;
            num /= i;
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d", &x, &k);

    x /= 5;

    int n = x + k;

    for (int i = 2; i <= n; i++) {
        fact(i, 1);
    }

    for (int i = 2; i <= k; i++) {
        fact(i, -1);
    }

    for (int i = 2; i <= n - k; i++) {
        fact(i, -1);
    }

    cerr << "FACTORIZED" << endl;
    
    BigInt result(1);

    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < divs[i]; j++) {
            result *= i;
        }
    }

    result.print();

    return 0;
}
