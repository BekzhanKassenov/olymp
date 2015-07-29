#include <iostream>
#include <cstdio>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

const int MAXN = 10;
const int MAXQ = 10;

int get_rand() {
    return rand();//((rand() << 16) ^ rand());
}

int main() {
    freopen("in", "w", stdout);
    
    srand(time(NULL));
    
    int n = rand() % MAXN + 1;
    int m = rand() % MAXN + 1;
    
    int w = rand() % MAXQ;
    
    cout << n << ' ' << m << ' ' << w << endl;
    
    for (int i = 0; i < w; i++) {
        int t = rand() & 1;
        
        int x = rand() % n;
        int y = rand() % m;
        
        int _x = x + rand() % (n - x);
        int _y = y + rand() % (m - y);
        
        cout << t << ' ' << x + 1 << ' ' << y + 1 << ' ' << _x + 1 << ' ' << _y + 1;
        
        if (t == 0)
            cout << ' ' << rand();
            
        cout << endl;
    }
    
    return 0;
}