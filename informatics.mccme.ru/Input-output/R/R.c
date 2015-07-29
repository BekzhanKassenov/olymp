#include <stdio.h>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n, k;
    scanf("%d%d", &n, &k);
    
    printf("%d", (n - k % n) % n);
    
    return 0;
}
