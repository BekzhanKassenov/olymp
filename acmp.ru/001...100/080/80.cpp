#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

const int MAXN = 110;

int pos, len;
char s[MAXN];

void error() {
    puts("ERROR");
    exit(0);
}

int parseInt() {
    if (pos >= len) {
        error();
    }

    bool flag = false;
    if (s[pos] == '-') {
        pos++;
        flag = true;
    }

    if (pos >= len || !isdigit(s[pos])) {
        error();
    }

    int num = 0;
    while (pos < len && isdigit(s[pos])) {
        num *= 10;
        num += s[pos] - '0';
        pos++;
    }

    if (flag && num == 0) {
        error();
    }

    if (flag) {
        num *= -1;
    }

    return num;
}

char parseSign() {
    if (s[pos] != '+' && s[pos] != '-' 
        && s[pos] != '*' && s[pos] != '/') {
        error();
    }

    return s[pos++];
}

void parseEqual() {
    if (s[pos] != '=') {
        error();
    }

    pos++;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    gets(s);
    len = strlen(s);

    int a = parseInt();
    char sign = parseSign();
    int b = parseInt();

    parseEqual();

    int c = parseInt();

    if (pos < len) {
        error();
    }

    bool res = false;
    switch (sign) {
        case '+':
            res = (a + b == c);
            break;

        case '-':
            res = (a - b == c);
            break;

        case '*':
            res = (a * b == c);
            break;

        case '/':
            res = (b != 0 && a == b * c);
            break;
    }

    if (res) {
        puts("YES");
    } else {
        puts("NO");
    }

    return 0;
}
