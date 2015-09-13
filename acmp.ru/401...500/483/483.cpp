#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 100010;

int n, sum;
char s[MAXN];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d\n", &n);
    gets(s);

    for (int i = 0; i < n; i++) {
        sum += s[i] - '0';
    }

    for (int i = n - 1; i >= 0; i--) {
        s[i] = (sum & 1) + '0';
        sum >>= 1;
    }

    for (int i = 0; i < n; i++) {
        if (s[i] != '0') {
            puts(s + i);
            return 0;
        }
    }

    puts("0");

    return 0;
}
