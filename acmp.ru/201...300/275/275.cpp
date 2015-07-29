#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

#define all(x) (x).begin(), (x).end()

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;
    
    string s;
    
    for (int i = 0; i < n; i++) {
        cin >> s;
        reverse(all(s));

        int sum = 0;

        for (size_t j = 0; j < s.size(); j++) {
            sum += (s[j] - '0') * (1 << (j % 3));
            sum %= 7;
        }
        
        cout << (sum ? "No" : "Yes") << endl;
    }
    
    return 0;
}
