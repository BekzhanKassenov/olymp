#include <iostream>
#include <cstdio>

using namespace std;

int cnt(int n) {
    int ans = 0;

    while (n) {
        ans += !(n & 1);
        n >>= 1;
    }

    return ans; 
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, k;

    cin >> n >> k;

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        if (cnt(i) == k)
            ans++;
    }

    cout << ans;
        
    return 0;
}