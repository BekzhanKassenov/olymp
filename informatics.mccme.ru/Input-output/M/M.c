#include <stdio.h>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int a, b;
    scanf("%d%d", &a, &b);
    
    int c = a;
    a = b;
    b = c;
    
    printf("%d %d", a, b);
    
    return 0;
}
