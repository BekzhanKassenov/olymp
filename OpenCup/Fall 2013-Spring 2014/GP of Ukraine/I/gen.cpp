#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    freopen("in", "w", stdout);
    
    ios_base :: sync_with_stdio(false);
    
    int n = 999;
    //int n = 9;
    cout << n << endl;
    
    for (int i = 0; i < n; i++) {
        if (i & 1)
            cout << 0 << ' ' << 0 << endl;
        else
            if (i != n - 1)
                cout << i + 2 << ' ' << i + 3 << endl;
    }
}