#include <iostream>
#include <cstdio>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    freopen("war.in", "w", stdout);
    
    srand(time(NULL));
    
    int n = rand() % 10 + 1;
    
    cout << n << endl;
    
    for (int i = 0; i < n; i++)
        cout << rand() << ' ';
        
    cout << endl;
    
    return 0;
}
