#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    freopen("bignim.in", "w", stdout);
    
    srand(time(NULL));
    
    int n = rand() % 10 + 1;
    
    cout << n << endl;
    
    for (int i = 0; i < n; i++) {
        cout << rand() % 10 + 1 << ' ';
    }
    
    return 0;
}
