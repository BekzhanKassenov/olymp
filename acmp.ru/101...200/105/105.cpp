#include <iostream>
#include <cstdio>
#include <cctype>
#include <cassert>

using namespace std;

const char signs[] = "+-*";

int lhs, n;
char s[100], buf[100];
int pos;

long long term();
long long expr();
long long eval();

long long term() {
    long long res = 0;
    //int temp = pos;

    if (s[pos] == '(') {
        pos++; // (
        res = expr();
        pos++; // )
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


long long expr() {
    //int temp = pos;

    long long res = term();

    while (pos < n && s[pos] != ')') {
        char sign = s[pos];
        pos++;

        switch (sign) {
            case '*':
                res *= term();
                break;
            case '+':
                res += term();
                break;
            case '-':
                res -= term();
                break;
        }
    }

    //printf("EXPR: pos=%d, res=%d\n", temp, res);

    return res;
}

long long eval() {
    pos = 0;
    //puts(s);
    long long res = expr();
    //puts("");

    return res;
}

bool go(int i) {
    if (i == n) {
        long long res = eval();

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

bool verify(char s[]) {
    for (int i = 0; s[i]; i++) {
        if (s[i] == ' ') {
            if (i == 0 || !s[i + 1]) {
                return false;
            }

            if (s[i - 1] != ')' && !isdigit(s[i - 1])) {
                return false;
            }

            if (s[i + 1] != '(' && !isdigit(s[i + 1])) {
                return false;
            }
        }
    }

    return true;
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

            s[n++] = ')';
        } else if (buf[i] != ' ') {
            s[n++] = buf[i];
        } else {
            if (isdigit(s[n - 1]) || s[n - 1] == ')') {
                s[n++] = ' ';
            }
        }
    }

    s[n] = '\0';

    assert(verify(s));

    if (!go(0)) {
        puts("-1");
    }

    return 0;
}
