#include <stdio.h>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n, m;
    scanf("%d%d", &n, &m);
    
    printf("%d", m / n + (m % n != 0));
    
    return 0;
}
