#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int n, k;
    stringstream ss;
    string s;
    int shift = 0;
    
    cin >> n >> k;
    
    ss << n;
    ss >> s;

    s = s.substr(k) + s.substr(0, k);

    for (size_t i = 0; i < s.size(); i++) {
        shift *= 10;
        shift += s[i] - '0';
    }

    cout << "Shift      " << k << endl;
    cout << "Number     " << n << endl;
    cout << "Cyc(N, k)  " << shift << endl;
    cout << "Code(N)    " << n + shift << endl;

    return 0;
}
