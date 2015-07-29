#include <iostream>
#include <cstdio>

using namespace std;

int a[3];
char s[55];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    gets(s);
    a[0] = 1;

    for (int i = 0; s[i]; i++) {
        if (s[i] == 'A')
            swap(a[0], a[1]);
        else if (s[i] == 'B')
            swap(a[1], a[2]);
        else
            swap(a[0], a[2]);
    }

    for (int i = 0; i < 3; i++)
        if (a[i] == 1) {
            printf("%d\n", i + 1);
            return 0;
        }

    return 0;
}
