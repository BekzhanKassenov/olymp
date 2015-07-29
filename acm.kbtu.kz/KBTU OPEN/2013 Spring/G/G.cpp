#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    freopen("honor.in", "r", stdin);
    freopen("honor.out", "w", stdout);

    int n;

    cin >> n;

    int ans = 0;

    while (n > 1) {
        ans++;
        
        if (n % 7 == 0) 
            n /= 7;
        else if (n % 3 == 0)
            n /= 3;
        else if (n % 2 == 0)
            n >>= 1;
        else
            n--;    
    }

    cout << ans << endl;

    return 0;
}
