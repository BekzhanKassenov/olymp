#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    int a, b, c;
    
    cin >> a >> b >> c;
    
    cout << max(max(a, b), c) - min(min(a, b), c);
    
    return 0;
}
