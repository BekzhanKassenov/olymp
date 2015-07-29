#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

#define all(x) (x).begin(), (x).end()

struct BigInt {
    vector <int> nmb;

    BigInt() {
        nmb.push_back(0);
    }

    BigInt(int n) {
        if (n == 0) {
            nmb.push_back(0);
            return;
        }
        
        while (n > 0) {
            nmb.push_back(n % 10);
            n /= 10;
        }
    }

    BigInt(char s) {
        nmb.resize(strlen(s));
        
        for (size_t i = 0; i < nmb.size(); i++) {
            nmb[i] = s[i] - '0';
        }

        reverse(all(nmb));
    }

    BigInt operator * (int k) const {
        BigInt result;

        result.nmb.clear();

        long long carry = 0;

        for (size_t i = 0; i < nmb.size(); i++) {
            carry += nmb[i] * k;
            result.push_back(carry % 10);
            carry /= 10;
        }

        while (carry > 0) {
            result.push_back(carry % 10);
            carry /= 10;
        }

        return result;
    }

    bool operator < (const BigInt& other) const {
        if (nmb.size() != other.nmb.size()) {
            return nmb.size() < other.nmb.size();
        }

        for (int i = nmb.size() - 1; i >= 0; i--) {
            if (nmb[i] != other.nmb[i]) {
                return nmb[i] < other.nmb[i];
            }
        }

        return false;
    }

    bool operator <= (const BigInt& other) const {
        return !(other < *this);
    }
};

BigInt power[500];
char s[210];
BigInt cur;
int n = 1;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    gets(s);

    cur = BigInt(s);
    power[0] = BigInt(1);

    for (int i = 2; i < 300; i++) {
        n = i;
        power[i] = power[i - 1] * 3;

        if (cur < power[i]) {
            break;
        }
    }

        

    return 0;
}
