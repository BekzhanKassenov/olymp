#include <iostream>
#include <cstdio>

using namespace std;

long long a, b, c, d;
int T;

bool gcd() {
    if (a == c && b == d) {
        return true;
    }

    if (b == 0) {
        return false;
    }

    while (b > 0) {
        //cout << a << ' ' << b << ' ' << c << ' ' << d << endl;
        if (b == d) {
            if (a % b == c % b && a >= c && c >= d) {
                return true;
            }
        }

        a %= b;
        
        if (a == c && b == d) {
            return true;
        }

        swap(a, b);
    }

    return false;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &T);

    while (T--) {
        scanf("%I64d%I64d%I64d%I64d", &a, &b, &c, &d);

        if (gcd()) {
            puts("YES");
        } else {
            puts("NO");
        }
    }

    return 0;   
}
