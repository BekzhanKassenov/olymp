#include <iostream>
#include <cstdio>

using namespace std;

int a, b;
char res[10000];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    scanf("%d/%d", &a, &b);

    printf("%d", a / b);
    if (a % b == 0) {
        putchar('\n');
        return 0;
    }

    putchar('.');

    while (true) {
        
    }

    return 0;
}
