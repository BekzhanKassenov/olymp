#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int main() {
    setlocale(LC_ALL, "Rus");
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int k, n;

    cin >> k >> n;

    string s;
    getline(cin, s);

    stringstream ss;
    
    for (int i = 0; i < n; i++) {
        getline(cin, s);

        string :: iterator it = s.begin();
        
        while (*it == ' ')
            it++;
            
        s.erase(s.begin(), it);
        
        it = --s.end();
        
        while (*it == ' ')
            it--;
            
        s.erase(it + 1, s.end());
        
        if ((int)s.size() > k) {
            cout << "Impossible.";
            return 0;
        }
        
        int l = (k - s.size()) / 2;
        int r = (k - s.size() + 1) / 2;
        
        while (l--)
            ss << ' ';
            
        ss << s;
        
        while (r--)
            ss << ' ';
            
        ss << endl;
    }
    
    cout << ss.str();

    return 0;
}
