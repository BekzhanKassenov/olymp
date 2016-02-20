#include <iostream>
#include <cstdio>
#include <cmath>
#include <cctype>

using namespace std;

int n;
long long q;

template <class T>
inline T sqr(T x) {
    return x * x;
}

long long read_double() {
    string s;
    cin >> s;

    while (s.length() != 5u) {
        s.append(1, '0');
    }

    long long res = 0;
    for (char c: s) {
        if (isdigit(c)) {
            res *= 10;
            res += c - '0';
        }
    }

    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n;
    q = read_double();

    cerr << q << endl;

    long long x, y, _y1, x1;

    for (int i = 0; i < n; i++) {
        cin >> x >> y >> x1 >> _y1;
        if ((sqr(x) + sqr(y)) * sqr(q) < (sqr(x1) + sqr(_y1)) * 1000000ll) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    
    return 0;
}
