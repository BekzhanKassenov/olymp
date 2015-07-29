#include <stdio.h>

int max(int a, int b) {
    return ((a > b) ? a : b);
}

int min(int a, int b) {
    return ((a < b) ? a : b);
}

int main(void) {
    FILE *input  = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");
    
    int a, b, c;
    
    fscanf(input, "%i%i%i", &a, &b, &c);
    
    fprintf(output, "%i", max(max(a, b), c) - min(min(a, b), c));
    
    return 0;
}

