#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

bool mem1[500 * 100 + 10], mem2[500 * 100 + 10];
bool *dp1, *dp2;
int n, a[510];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
        
    dp1 = mem1;
    dp2 = mem2;

    dp1[0] = true;
    dp1[a[0]] = true;

    for (int i = 1; i < n; i++) {
        memset(dp2, false, sizeof(bool) * (500 * 100 + 10));
        dp2[0] = true;
        
        for (int sum = 1; sum <= 500 * 100; sum++) {
            if (sum - a[i] >= 0)
                dp2[sum] |= dp1[sum - a[i]];
            
            dp2[sum] |= dp1[sum];
        }
        
        swap(dp1, dp2);
    } 
    
    int ans = 0;
    
    for (int sum = 0; sum <= 500 * 100; sum++)
        ans += dp1[sum];
        
    printf("%d", ans);
    
    return 0;
}
