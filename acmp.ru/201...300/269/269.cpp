#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int check(const string& s1, const string& s2) {
    for (size_t i = 0; i < min(s1.size(), s2.size()); i++) {
        if (s1[i] == '2' && s2[i] == '2')
            return (int)1e9;
    }

    int l = 1000, r = 0;
    
    for (size_t i = 0; i < max(s1.size(), s2.size()); i++) {
        if ((i < s1.size() && s1[i] != '0') || (i < s2.size() && s2[i] != '0')) {
            l = min(l, (int)i);
            r = max(r, (int)i);
        }
    }

    return r - l + 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s, t;
    cin >> s >> t;

    int ans = s.size() + t.size();

    int len = s.size();
    string temp;

    for (int i = 0; i < len; i++)
        temp += '0';

    t = temp + t + temp;

    do {
        s = '0' + s;
        ans = min(ans, check(s, t));
    } while (s.size() < t.size());

    cout << ans << endl;

    return 0;
}