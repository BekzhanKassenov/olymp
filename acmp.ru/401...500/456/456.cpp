#include <iostream>
#include <cstdio>
#include <cassert>

using namespace std;

typedef pair <long long, long long> coeff;

coeff operator + (const coeff& a, const coeff& b) {
    return coeff(a.first + b.first, a.second + b.second);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long x, y;
    cin >> x >> y;

    coeff f1(1, 0);
    coeff f2(0, 1);

    for (int i = 3; i <= x; i++) {
        coeff f3 = f1 + f2;
        f1 = f2;
        f2 = f3;
    }

    for (long long firstDay = 1; firstDay * f2.first <= y; firstDay++) {
        long long temp = y - firstDay * f2.first;
        if (temp % f2.second == 0) {
            long long secondDay = temp / f2.second;
            if (secondDay < firstDay) {
                cout << firstDay << ' ' << secondDay << endl;
                return 0;
            }
        }
    }

    assert(false);

    return 0;
}