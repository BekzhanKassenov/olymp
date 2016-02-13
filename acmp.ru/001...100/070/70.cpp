#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

string s;
int n;

size_t minim(size_t a, size_t b) {
    return (a < b) ? a : b;
}

int main() {    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    cin >> s >> n;
    if (n > 0) {
        for (size_t i = 0; i < minim(s.length() * n, 1023ul); i++) {
            cout << s[i % s.length()];
        }

        cout << endl;

        return 0;
    }
    
    int len = s.length();
    n *= -1;

    if (len % n != 0) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }

    len /= n;
    for (size_t i = 0; i < s.length(); i++) {
        if (s[i] != s[i % len]) {
            cout << "NO SOLUTION" << endl;
            return 0;
        }
    }

    cout << s.substr(0, minim(len, 1023)) << endl;
    
    return 0;
}
