#include <stdio.h>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int h, a, b;
    
    scanf("%d%d%d", &h, &a, &b);
    
    int dh = h - a;
    int sh = a - b;
    
    printf("%d", 1 + dh / sh + (dh % sh + sh - 1) / sh);
    
    return 0;
}
