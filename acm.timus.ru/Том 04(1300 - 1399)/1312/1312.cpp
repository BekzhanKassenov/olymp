#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

typedef long long ll;

void sort(int& a, int& b, int& c) {
    int mx = max(max(a, b), c);
    int mn = min(min(a, b), c);
    
    b += a + c - mx - mn;
    a = mx;
    c = mn;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    ll h, w;
    cin >> h >> w;
    
    ll r1, r2, r3;
    cin >> r1 >> r2 >> r3;
    
    sort(r1, r2, r3);
    
    if (sqrt(2) * r1 - r1 >= 2 * r2) {
        printf("%.4lf %.4lf %.4lf %.4lf %.4lf %.4lf", r1, r1, (sqrt(2) * r1 - r1) / 2, (sqrt(2) * r1 - r1) / 2, 
    
    return 0;
}
