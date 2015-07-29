#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    freopen("death.in", "w", stdout);
    
    cout << 1000 << ' ' << 1000 << endl;
    
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            cout << i * 1000 + j + 1 << ' ';
        }
        cout << endl;
    }
    
    return 0;
}
