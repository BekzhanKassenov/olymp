#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 100010;
const char echars[] = "=+-*/0123456789)(\n";

char s[MAXN];
char buf[MAXN];
int n;

bool expr(char c) {
    for (char cc: echars) {
        if (c == cc) {
            return true;
        }
    }

    return false;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    while (fgets(buf, MAXN, stdin) != NULL) {
        strcat(s, buf);
    }


    n = strlen(s);

    bool comment = false;
    int balance = 0;
    int pos = 0;

    bool ok = true;

    while (pos < n) {
        if (!comment && pos + 1 < n && s[pos] == '(' && s[pos + 1] == '*') {
            // comment opened

            comment = true;
            pos += 2;
        } else if (comment) {
            // we are in comment - ignore everithing, except *)

            if (pos + 1 < n && s[pos] == '*' && s[pos + 1] == ')') {
                comment = false;
                pos += 2;
            } else {
                pos++;
            }
        } else if (balance > 0) {
            // we are in expression
            if (!expr(s[pos])) {
                // bad if current character should not be in expression
                ok = false;
            } else {
                // Check balance of expression
                if (s[pos] == '(') {
                    balance++;
                } else if (s[pos] == ')') {
                    balance--;
                }
            }

            pos++;
        } else {
            if (s[pos] == '(') {
                balance++;
            } else if (s[pos] == ')') {
                // we are supposed to be in simple text
                // but char is ')'
                ok = false;
            }
            
            pos++;
        }
    }

    ok &= (balance == 0) && !comment;

    if (ok) {
        puts("YES");
    } else {
        puts("NO");
    }

    return 0;
}
