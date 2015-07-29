#include <iostream>
#include <cstdio>
#include <vector>
 
using namespace std;
 
int n;
 
char get(int pos, int len, char res = 'z') {
    if (pos == 1)
        return res;
 
    res--;
    pos--;
    len >>= 1;
 
    if (pos > len)
        pos -= len;
 
    return get(pos, len, res);
}
 
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    scanf("%d", &n);
 
    putchar(get(n, (1 << 26) - 1));
 
    return 0;
}