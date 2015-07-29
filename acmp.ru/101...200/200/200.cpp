#include <iostream>
#include <cstdio>

using namespace std;

long long divisor_power(int num, int divisor, int power) {
    long long res = 0;
    
    while (num) {
        num /= divisor;
        res += num;
    }
    
    return res / power;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n, k;
    
    cin >> n >> k;
    
    long long res = 100000000 * 1ll * 100000000;
    
    for (int i = 2; k > 1; i++) {
        int cnt = 0;
        
        while (k % i == 0) {
            k /= i;
            cnt++;
        }
        
        if (cnt)
            res = min(res, divisor_power(n, i, cnt));
    }
    
    cout << res;
    
    return 0;
}
