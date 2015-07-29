#include <stdio.h>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int hh, mm, ss;
    scanf("%d%d%d", &hh, &mm, &ss);
    
    int seconds = (hh * 60 + mm) * 60 + ss;

    scanf("%d%d%d", &hh, &mm, &ss);

    seconds = (hh * 60 + mm) * 60 + ss - seconds;

    printf("%d", seconds); 
    
    return 0;
}
