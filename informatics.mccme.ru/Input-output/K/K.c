#include <stdio.h>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    scanf("%d", &n);
    
    n %= (24 * 60);
    
    printf("%d %d", n / 60, n % 60);
    
    return 0;
}
