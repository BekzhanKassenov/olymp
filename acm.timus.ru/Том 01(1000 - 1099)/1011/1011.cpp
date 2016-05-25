#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int read() {
    string s;
    cin >> s;

    auto it = s.find('.');

    string before;
    string after;
    
    if (it != string::npos) {
        for (decltype(it) i = 0; i < it; i++) {
            before.push_back(s[i]);
        }

        for (decltype(it) i = it + 1; i < s.size(); i++) {
            after.push_back(s[i]);
        }
    } else {
        before = s;
    }

    while (before.size() < 2ul) {
        before.insert(before.begin(), '0');
    }

    while (after.size() < 2ul) {
        after.push_back('0');
    }

    int ans = 0;
    for (char dig: before) {
        ans *= 10;
        ans += dig - '0';
    }

    for (char dig: after) {
        ans *= 10;
        ans += dig - '0';
    }

    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    int a = read();
    int b = read();

    int den = 10000;
    for (int i = 1; ; i++) {
        int lo = i * a / den + 1;
        int hi = i * b / den;

        if (hi * den == i * b) {
            hi--;
        }

        if (lo <= hi) {
            printf("%d\n", i);
            break;
        }
    }

    return 0;
}
