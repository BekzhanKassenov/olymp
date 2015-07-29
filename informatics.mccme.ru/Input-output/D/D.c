#include <stdio.h>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n, k;
    scanf("%d%d", &n, &k);

    printf("%d", k % n);
    return 0;
}
