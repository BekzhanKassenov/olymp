#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

char a, b, c, d;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%c%c %c%c\n", &a, &b, &c, &d);

    a -= 'a';
    b -= '0' + 1;

    c -= 'a';
    d -= '0' + 1;

    if ((a + b) % 2 != (c + d) % 2) {
        puts("NO");
        return false;
    }

    int diffh = d - b;
    int diffw = abs(a - c);

    puts(diffh >= diffw ? "YES" : "NO");

    return 0;
}
