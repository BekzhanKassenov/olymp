#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>

using namespace std;

#define all(x) (x).begin(), (x).end()

int to_dec(char c)
{
    if (c >= '0' && c <= '9')
        return c - '0';

    if (c >= 'A' && c <= 'Z')
        return c - 'A' + 10;
}

char to_let(int dig) {
    if (0 <= dig && dig <= 9) {
        return '0' + dig;
    }

    return 'A' + dig - 10;
}

string f(int n, int b) {
    if (n == 0) {
        return "0";
    }

    string res;

    while (n > 0) {
        res.append(1, to_let(n % b));
        n /= b;
    }

    reverse(all(res));

    return res;
}

string s;
int n;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> s;
    cin >> n;

    int b = 0;

    for (size_t i = 0; i < s.length(); i++) {
        b = max(b, to_dec(s[i]));
    }

    for (int i = b + 1; i <= 36; i++) {
        if (s == f(n, i)) {
            cout << i << endl;
            return 0;
        }
    }

    cout << 0 << endl;

    return 0;
}
