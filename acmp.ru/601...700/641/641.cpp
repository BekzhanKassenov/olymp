#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char s[255];
int x, y = 1, n;

void update(int i, int j) {
    int ptr1 = 0, ptr2 = 0;

    for (int q = 0; q < n - 2; q++) {
        while (ptr1 == i || ptr1 == j)
            ptr1++;

        while (ptr2 == x || ptr2 == y)
            ptr2++;
        
        if (s[ptr1] != s[ptr2]) {
            if (s[ptr1] > s[ptr2])
                x = i, y = j;

            return;
        }

        ptr1++, ptr2++;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    gets(s);
    n = strlen(s);

    for (int i = 0; s[i]; i++) {
        for (int j = i + 1; s[j]; j++) {
            update(i, j);
        }
    }

    for (int i = 0; s[i]; i++) {
        if (i != x && i != y)
            putchar(s[i]);
    }

    puts("");

    return 0;
}
