#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>

using namespace std;

const int MAXN = 1010;

char s[MAXN];
int pos;

void removeSpaces() {
    int last = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] != ' ') {
            s[last++] = s[i];
        }
    }

    s[last] = '\0';
}

int parseInt();
int fact();
int expr();

int parseInt() {
    int mul = 1;
    if (s[pos] == '-') {
        mul = -1;
        pos++;
    }

    int result = 0;
    while (s[pos] && isdigit(s[pos])) {
        result *= 10;
        result += s[pos] - '0';
        pos++;
    }

    return result * mul;
}

int fact() {
    if (s[pos] == '(') {
        pos++; // skip (
        int result = expr();
        pos++; // skip )

        return result;
    }

    if (s[pos] == '-' && s[pos + 1] == '(') {
        pos += 2; // skip -(
        int result = -expr();
        pos++; // skip )

        return result;
    }

    return parseInt();
}

int expr() {
    int result = fact();

    while (s[pos] && s[pos] != ')') {
        if (s[pos] == '+') {
            pos++; // skip +
            result += fact();
        } else if (s[pos] == '-') {
            pos++; // skip -
            result -= fact();
        } else if (s[pos] == '*') {
            pos++; // skip *;
            result *= fact();
        }
    }

    return result;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    gets(s);

    removeSpaces();

    printf("%d\n", expr());

    return 0;
}
