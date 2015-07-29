#include <stdio.h>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n, a, b;
    scanf("%d%d%d", &a, &b, &n);
    
    a *= n;
    b *= n;
    
    a += b / 100;
    b %= 100;
    
    printf("%d %d", a, b);
    
    return 0;
}
