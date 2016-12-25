#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define all(x) (x).begin(), (x).end()

struct BigInt {
    vector <int> numb;

    BigInt() {
        trim();
    }

    void from(int n) {
        while (n > 0) {
            numb.push_back(n % 10);
            n /= 10;
        }
        trim();
    }

    void trim() {
        while (numb.size() > 1u && numb.back() == 0) {
            numb.pop_back();
        }
    }

    bool power10(long long n) const {
        while (n > 1 && n % 10 == 0) {
            n /= 10;
        }

        return n == 1;
    }

    BigInt& operator *= (long long k) {
        if (power10(k)) {
            reverse(all(numb));
            while (k > 1) {
                numb.push_back(0);
                k /= 10;
            }
            reverse(all(numb));
            return *this;
        }

        long long carry = 0;
        for (size_t i = 0; i < numb.size(); i++) {
            carry += numb[i] * k;
            numb[i] = carry % 10;
            carry /= 10;
        }

        while (carry > 0) {
            numb.push_back(carry % 10);
            carry /= 10;
        }

        trim();
        return *this;
    }

    bool operator < (const BigInt& other) const {
        if (numb.size() != other.numb.size()) {
            return numb.size() < other.numb.size();
        }

        for (int i = numb.size() - 1; i >= 0; i--) {
            if (numb[i] != other.numb[i]) {
                return numb[i] < other.numb[i];
            }
        }

        return false;
    }
};

struct Mass {
    long long val;
    string unit;

    BigInt in_mg;

    Mass() {}

    long long get_mul(char c) {
        switch (c) {
            case 'm':
                return 1ll;
            case 'n':
                return 1000ll;
            case 'k':
                return 1000000ll;
            case 'M':
                return 1000000000ll;
            case 'G':
                return 1000000000000ll;
        }

        return 0;
    }

    long long get_unit(char c) {
        switch (c) {
            case 'g':
                return 1;
            case 't':
                return 1000000;
            case 'p':
                return 16380;
        }

        return 0;
    }

    void init() {
        string temp = unit;
        if (temp.size() == 1u) {
            temp = "n" + temp;
        }

        in_mg.from(val);
        in_mg *= get_mul(temp[0]);
        in_mg *= get_unit(temp[1]);
    }

    bool operator < (const Mass& other) const {
        return in_mg < other.in_mg;
    }   
};

int n;
Mass mass[1010];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> mass[i].val >> mass[i].unit;
        mass[i].init();
    }   

    stable_sort(mass, mass + n);

    for (int i = 0; i < n; i++) {
        cout << mass[i].val << ' ' << mass[i].unit << endl;
    }   

	return 0;
}
