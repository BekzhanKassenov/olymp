#include <iostream>
#include <cstdio>
 
using namespace std;
 
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    int a, b, c;
 
    scanf("%d%d%d", &a, &b, &c);
 
    if (a + b > c && b + c > a && a + c > b) {
        puts("YES");
    } else {
        puts("NO");
    }
    return 0;
}