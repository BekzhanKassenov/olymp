#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int ans = 2 * (n / k);

    if (n % k != 0)
        ans++;

    if (n < k || n % k > k / 2)
        ans++;

    cout << ans;
    
    return 0;   
}