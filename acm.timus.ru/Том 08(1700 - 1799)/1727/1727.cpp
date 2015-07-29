#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int sum(int n) {
    int res = 0;
    
    while (n) {
        res += n % 10;
        n /= 10;
    }
    
    return res;
}

int get_max(int n) {
    int cur = 0;
    
    while (n > 0) {
        cur = cur * 10 + ((n >= 9) ? (9) : n);
        
        n -= 9;
    }
    
    return cur;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    int n;
    
    cin >> n;
    
    int cur = 99999;
    
    vector <int> ans;
    
    while (n >= sum(cur)) {
        if (cur <= 0) {
             cout << -1;
             return 0;
        }
        ans.push_back(cur);
        n -= sum(cur);
        
        cur--;
    }
    
    if (n) {
        if (get_max(n) > cur) {
            cout << -1;
            return 0;
        }
        
        ans.push_back(get_max(n));
    }
        
    cout << ans.size() << endl;
    
    for (size_t i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';
        
    cout << endl;
}