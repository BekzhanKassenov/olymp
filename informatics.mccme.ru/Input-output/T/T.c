#include <stdio.h>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    
    scanf("%d", &n);
    
    printf("%d", (n / 1000 == n % 10) && ((n / 100) % 10 == (n / 10) % 10));
    
    return 0;
}
