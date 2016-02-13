/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, k;
string s[4];

bool vowel(char c) {
    for (char ch : "aeiou") {
        if (ch == c) {
            return true;
        }
    }

    return false;
}

void cut(string& s, int k) {
    int pos = s.size() - 1;
    while (pos >= 0 && k > 0) {
        if (vowel(s[pos])) {
            k--;
        }

        if (k != 0) {
            pos--;
        }
    }

    if (k == 0) {
        s = s.substr(pos);
    } else {
        s.clear();
    }
}

bool equal(const string& s, const string& t) {
    if (s.size() != t.size()) {
        return false;
    }

    return s == t;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    cin >> n >> k;

    set <string> ans;
    bool hasFull = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> s[j];
        }

        bool ok = true;
        for (int j = 0; j < 4; j++) {
            cut(s[j], k);
            if (s[j].empty()) {
                ok = false;
            }
        }

        if (!ok) {
            cout << "NO" << endl;
            return 0;
        }

        if (equal(s[0], s[1]) && equal(s[1], s[2]) && equal(s[2], s[3])) {
            hasFull = true;
            continue;
        }

        bool found = false;
        if (equal(s[0], s[1]) && equal(s[2], s[3])) {
            ans.insert("aabb");
            found = true;
        }

        if (equal(s[0], s[2]) && equal(s[1], s[3])) {
            ans.insert("abab");
            found = true;
        }

        if (equal(s[0], s[3]) && equal(s[1], s[2])) {
            ans.insert("abba");
            found = true;
        }

        if (!found) {
            cout << "NO" << endl;
            return 0;
        }
    }

    if (ans.size() > 1u) {
        cout << "NO" << endl;
        return 0;
    }

    if (ans.size() == 1u) {
        cout << *ans.begin() << endl;
        return 0;
    }

    if (hasFull) {
        cout << "aaaa" << endl;
        return 0;
    }

    cout << "NO" << endl;

    return 0;
}
