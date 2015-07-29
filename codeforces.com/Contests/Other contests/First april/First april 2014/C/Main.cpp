#include <iostream>
#include <cstdio>

using namespace std;

int a[] = {1, 1, 2, 7, 4};

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    int b[5];
    
    for (int i = 0; i < 5; i++)
        cin >> b[i];
        
    int ans = 500;
    
    for (int i = 0; i < 5; i++) {
        if (b[i] == 0)
            ans = 0;
        else
            ans = min(ans, b[i] / a[i]);
    }
    
    cout << ans;
    
    return 0;
}
