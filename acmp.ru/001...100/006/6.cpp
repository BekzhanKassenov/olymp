#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

bool letter(char c) {
    return 'A' <= c && c <= 'H';
}

bool digit(char c) {
    return '1' <= c && c <= '8';
}

bool valid(const string& s) {
    if (s.length() != 5u) {
        return false;
    }

    if (!letter(s[0])) {
        return false;
    }

    if (!digit(s[1])) {
        return false;
    }

    if (s[2] != '-') {
        return false;
    }

    if (!letter(s[3])) {
        return false;
    }

    if (!digit(s[4])) {
        return false;
    }

    return true;
}

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    string s;
    cin >> s;
    
    if (!valid(s)) {
        cout << "ERROR" << endl;
        return 0;
    }

    int xs = s[0] - 'A';
    int ys = s[1] - '0';

    int xf = s[3] - 'A';
    int yf = s[4] - '0';

    pair <int, int> diff(abs(xs - xf), abs(ys - yf));
    if (diff.first > diff.second) {
        swap(diff.first, diff.second);
    }

    if (diff == make_pair(1, 2)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
