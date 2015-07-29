#include <iostream>
#include <cstdio>
#include <set>
#include <memory.h>

using namespace std;

struct BigInt {
    static const int LEN = 20;

    int a[LEN];

    BigInt() {
        memset(a, 0, sizeof a);
    }

    BigInt(int n) {
        memset(a, 0, sizeof a);

        for (int i = LEN - 1; i >= 0; i--) {
            a[i] = n % 10;
            n /= 10;
        }
    }

    BigInt operator + (const BigInt& p) const {
        BigInt result;
        int pos = LEN - 1;

        for (int i = LEN - 1; i >= 0 && pos >= 0; i--) {
            int sum = a[i] + p.a[i];

            do {
                result.a[pos] = sum % 10;
                sum /= 10;
                pos--;
            } while (sum > 0 && pos >= 0);
        }

        return result;
    }

    bool operator < (const BigInt& p) const {
        return memcmp(a, p.a, sizeof(int) * LEN) < 0;
    }

    void print() const {
        int pos = 0;

        while (pos < LEN && a[pos] == 0) {
            pos++;
        }

        while (pos < LEN) {
            printf("%d", a[pos]);
            pos++;
        }

        puts("");
    }
};

int a, b, c;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d%d", &a, &b, &c);

    BigInt A(a), B(b), C(c);

    BigInt abc = A + B + C;
    BigInt acb = A + C + B;
    BigInt bac = B + A + C;
    BigInt bca = B + C + A;
    BigInt cab = C + A + B;
    BigInt cba = C + B + A;

    /*
    abc.print();
    acb.print();
    bac.print();
    bca.print();
    cab.print();
    cba.print();
    */

    set <BigInt> Set;

    Set.insert(abc);
    Set.insert(acb);
    Set.insert(bac);
    Set.insert(bca);
    Set.insert(cab);
    Set.insert(cba);

    if (Set.size() == 1u) {
        puts("NO");
    } else {
        puts("YES");
    }

    for (set <BigInt> :: iterator it = Set.begin(); it != Set.end(); it++) {
        it -> print();
    }
    
    return 0;	
}
