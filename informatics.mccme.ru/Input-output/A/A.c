#include <stdio.h>
#include <math.h>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    double a, b;
    scanf("%lf%lf", &a, &b);
    
    printf("%.10lf", sqrt(a * a + b * b));
    
    return 0;
}