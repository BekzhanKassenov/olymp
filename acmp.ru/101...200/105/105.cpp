#include <iostream>
#include <cstdio>
#include <cctype>

using namespace std;

const char signs[] = "+-*";

int lhs, n;
char s[100], buf[100];
int pos;

int term();
int expr();
int eval();

int term() {
    int res = 0;
    //int temp = pos;

    if (s[pos] == '(') {
        pos++;
        res = expr();
        pos++;
    } else {
        while (pos < n && isdigit(s[pos])) {
            res *= 10;
            res += s[pos] - '0';
            pos++;
        }
    }

    //printf("TERM: pos=%d, res=%d\n", temp, res);

    return res;
}


int expr() {
    //int temp = pos;

    int res = term();

    while (pos < n && s[pos] != ')') {
        char sign = s[pos];
        pos++;

        if (sign == '*') {
            res *= term();
        } else if (sign == '+') {
            res += term();
        } else {
            res -= term();
        }
    }

    //printf("EXPR: pos=%d, res=%d\n", temp, res);

    return res;
}

int eval() {
    pos = 0;
    //puts(s);
    int res = expr();
    //puts("");

    return res;
}

bool go(int i) {
    if (i == n) {
        int res = eval();

        if (res == lhs) {
            printf("%d=%s\n", lhs, s);
            return true;
        }

        return false;
    }

    bool res = false;
    if (s[i] == ' ') {
        for (int j = 0; j < 3 && !res; j++) {
            s[i] = signs[j];
            res |= go(i + 1);
        }

        s[i] = ' ';
    } else {
        res = go(i + 1);
    }

    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d = ", &lhs);
    gets(buf + 1);

    for (int i = 1; buf[i]; i++) {
        if (buf[i] == ')') {
            while (n > 0 && s[n - 1] == ' ') {
                n--;
            }

            s[n++] = buf[i];
        } else if (buf[i] != ' ') {
            s[n++] = buf[i];
        } else {
            if (isdigit(s[n - 1]) || s[n - 1] == ')') {
                s[n++] = buf[i];
            }
        }
    }

    s[n] = '\0';

    if (!go(0)) {
        puts("-1");
    }

    return 0;
}
