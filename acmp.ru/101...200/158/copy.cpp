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

    BigInt(const BigInt& b) : nmb(b.nmb) { }

    BigInt(int n) {
        while (n) {
            nmb.push_back(n % BASE);
            n /= BASE;
        }

        if (nmb.empty())
            nmb.push_back(0);
    }

    void operator += (const BigInt& p) {
        int flag = 0;

        for (size_t i = 0; i < nmb.size(); i++) {
            flag += nmb[i];

            if (i < p.nmb.size())
                flag += p.nmb[i];

            nmb[i] = flag % BASE;
            flag /= BASE;
        }

        for (size_t i = nmb.size(); i < p.nmb.size(); i++) {
            flag += p.nmb[i];
            nmb.push_back(flag % BASE);
            flag /= BASE;
        }

        while (flag) {
            nmb.push_back(flag % 10);
            flag /= 10;
        }
    }


    void print() {
        for (int i = nmb.size() - 1; i >= 0; i--)
            cout << nmb[i];
        cout << endl;   
    }
};

int n, k;
BigInt dp[510][510];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d %d\n", &n, &k);
    n /= 5;
    k+;

    return 0;
}
