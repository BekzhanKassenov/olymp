#include <stdio.h>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    scanf("%d", &n);
    
    printf("%d", n + 2 - n % 2);
    
    return 0;
}
