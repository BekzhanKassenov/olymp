#include <stdio.h>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int a, b;
    
    scanf("%d%d", &a, &b);
    
    int c = a - b;
    
    printf("%d", (c < 0) * b + (c >= 0) * a);
    
    return 0;
}
