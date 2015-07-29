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

    bool flag = false;

    for (int i = n - 1; i >= 0; i--) {
        if ((sum >> i) & 1)
            flag = true;

        if (flag)
            putchar(((sum >> i) & 1) + '0');    
    }

    putchar('\n');

    return 0;
}
