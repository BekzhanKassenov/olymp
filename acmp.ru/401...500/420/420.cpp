#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

size_t pos;
string s;

bool tryParseInt() {
    string ans;
    while (pos < s.length() && isdigit(s[pos])) {
        ans += s[pos++];
    }
    if (ans == "1" || ans[0] == '0')
        return false;
    return true;
}

pair <string, bool> parseElem() {
    string elem;
    if (!isupper(s[pos])) {
        return make_pair("", false);
    }
    elem += s[pos++];
    if (pos < s.length() && islower(s[pos])) {
        elem += s[pos++];
    }
    return make_pair(elem, true);
}

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin >> s;
    string prevElem;
    while (pos < s.length()) {
        pair <string, bool> res = parseElem();
        if (!res.second || prevElem == res.first) {
            cout << "NO" << endl;
            return 0;
        }
        prevElem = res.first;
        if (!tryParseInt()) {
            cout << "NO" << endl;
            return 0;
        }
    }
   cout << "YES" << endl;
   return 0;
} 
