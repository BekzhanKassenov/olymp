#include <stdio.h>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    scanf("%d", &n);
    
    printf("The next number for the number %i is %i.\n", n, n + 1);
    printf("The previous number for the number %i is %i.\n", n, n - 1);
    
    return 0;
}
