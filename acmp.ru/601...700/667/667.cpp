#include <iostream>
#include <cstdio>
 
using namespace std;
 
int n, m, k, ans;
 
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    scanf("%d%d%d", &n, &m, &k);
 
    if (k < 3 && n > 0) {
        puts("0");
        return 0;
    }
 
    while (n) {
        if (m < 2) {
            puts("0");
            return 0;
        }
 
        ans++;
         
        m -= 2;
 
        if (n >= k - 2)
            n -= k - 2;
        else {
            m -= k - 2 - n;
            n = 0;
        }
    }
 
    if (m > 0)
        ans += (m + k - 1) / k;
 
    printf("%d\n", ans);
 
    return 0;
}