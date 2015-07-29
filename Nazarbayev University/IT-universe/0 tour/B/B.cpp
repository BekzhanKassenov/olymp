#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
    freopen("search.in", "r", stdin);
    freopen("search.out", "w", stdout);
    
    int n;
    cin >> n;
    
    vector <int> a(n);
    
    for (int i = 0; i < n; i++)
        cin >> a[i];
        
    int x;
    cin >> x;
    
    int ans = 0;
    
    
    for (int i = 0; i < n; i++)
        ans += a[i] == x;
        
    cout << ans;
    return 0;
}

