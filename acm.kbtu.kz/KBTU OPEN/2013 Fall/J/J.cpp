#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    freopen("random-number.in", "r", stdin);
    freopen("random-number.out", "w", stdout);

    int n;
    
    cin >> n;

    printf("%.9lf", n * 4.5);
   
    return 0;
}
