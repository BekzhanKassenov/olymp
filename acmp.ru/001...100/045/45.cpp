#include <iostream>
#include <cstdio>

using namespace std;

int n;
int a[10];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    cin >> n;
    
    if (n == 0) {
        cout << 10 << endl;
        return 0;
    }

    if (1 <= n && n <= 9) {
        cout << n << endl;
        return 0;
    }

    for (int i = 9; i >= 2; i--) {
        while (n % i == 0) {
            a[i]++;
            n /= i;
        }
    }

    if (n != 1) {
        cout << -1 << endl;
        return 0;
    }
    
    for (int i = 2; i < 10; i++) {
        for (int j = 1;j <= a[i]; j++) {
            cout << i;
        }
    }

    cout << endl;

    return 0;   

}
