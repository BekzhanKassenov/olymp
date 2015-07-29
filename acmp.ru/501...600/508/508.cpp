#include <iostream>
#include <cstdio>

using namespace std;

int n, a, b, c, d;
char ch;
long long cur;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d\n", &n);

    for (int i = 0; i < n; i++) {
        scanf("%c %d %d %d %d\n", &ch, &a, &b, &c, &d);

        long long to_print = -1;

        if (ch == 'B')
            to_print = cur - b + c;

        printf("%I64d ", to_print);

        cur -= a + b;
        cur += c + d;
    }

    return 0;
}
