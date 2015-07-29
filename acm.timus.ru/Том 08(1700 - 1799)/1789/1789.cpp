#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    int n;
    cin >> n;
    
    if (n == 1) {
        cout << 1 << endl << 1;
    } else if (n == 2) {
        cout << 2 << endl << 1 << ' ' << 1;
    } else {
    
        vector <int> ans;
    
        for (int i = 2; i < n; i++) {
            ans.push_back(i);
        }
    
        for (int i = n - 1; i >= 2; i--) {
            ans.push_back(i);
        }
        
        cout << ans.size() << endl;
        
        for (size_t i = 0; i < ans.size(); i++)
            cout << ans[i] << ' ';
    }
    
    return 0;
}
