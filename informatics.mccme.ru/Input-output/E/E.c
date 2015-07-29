#include <stdio.h>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int v, t;
    scanf("%d%d", &v, &t);
    
    printf("%d", ((v * t % 109) + 109) % 109);
    
    return 0;
}
