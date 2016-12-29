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

const char alphabet[] = {' ', 'A', 'H', 'I', 'M', 'O', 'T', 'U', 'V', 'W', 'X', 'Y'};
const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 1050;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int toInt(char c) {
    for (int i = 0; i <= 11; i++) {
        if (c == alphabet[i]) {
            return i;
        }
    }

    return -1;
}

char toChar(int n) {
    if (n < 0 || n > 11) {
        return '\0';
    }

    return alphabet[n];
}

int getDig(int& carry) {
    if (carry % 11 == 0) {
        carry = carry / 11 - 1;
        return 11;
    }

    int res = carry % 11;
    carry /= 11;
    return res;
}

void solve(int k, string& s) {
    reverse(all(s));
    string conv;
    while (k > 0) {
        conv.push_back(toChar(getDig(k)));
    }

    int carry = 0;
    for (size_t i = 0; i < s.size(); i++) {
        carry += toInt(s[i]);
        if (i < conv.size()) {
            carry += toInt(conv[i]);
        }

        s[i] = toChar(getDig(carry));
    }

    for (size_t i = s.size(); i < conv.size(); i++) {
        carry += toInt(conv[i]);
        s.push_back(toChar(getDig(carry)));
    }

    if (carry != 0) {
        s.push_back('A');
    }

    reverse(all(s));
}

int k;
string s;

int main() {
    ios_base::sync_with_stdio(false);
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    int T;
    cin >> T;

    while (T--) {
        cin >> k >> s;
        solve(k, s);
        cout << s << endl;
    }
    
    return 0;
}
