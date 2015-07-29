#include <cstdio>
#include <iostream>
#include <string>
#include <cassert>

using namespace std;

string s;
size_t pos;
long long x;

long long power(long long base, long long st) {
    long long result = 1;

    for (long long i = 0; i < st; i++) {
        result *= base;
    }

    return result;
}

long long formula();
long long expr();
long long fact();
long long term();

long long formula() {
    return expr();
}

long long num() {
    long long res = 0;
    while (pos < s.size() && isdigit(s[pos])) {
        res *= 10;
        res += s[pos] - '0';
        pos++;
    }

    return res;
}

long long term() {
    if (s[pos] == 'x') {
        long long res = x;
        pos++;

        if (s[pos] == '^') {
            pos++;
            int n = num();
            res = power(x, n);
        }

        return res;
    }

    return num();
}

long long fact() {
    long long res = term();

    while (pos < s.size() && s[pos] == '*') {
        pos++;
        res *= term();
    }

    return res;
}

long long expr() {
    long long res = fact();

    while (pos < s.size()) {
        if (s[pos] == '-') {
            pos++;
            res -= fact();
        } else if (s[pos] == '+') {
            pos++;
            res += fact();
        }
    }

    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    getline(cin, s);

    scanf("%I64d", &x);

    if (s[0] == '-') {
        s = "0" + s;
    }

    printf("%I64d\n", formula());

    return 0;
}
