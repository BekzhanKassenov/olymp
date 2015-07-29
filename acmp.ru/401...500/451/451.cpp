#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cctype>

using namespace std;

const int MAXN = 210;
char SIN[] = "sin";
char COS[] = "cos";

char s[MAXN];
int pos;

double expr();
double term();
double fact();
double func();
double numb();
void skip_spaces();
void error();
bool compare();

void skip_spaces() {
    while (isspace(s[pos])) {
        pos++;
    }
}

void error() {
    puts("Error");
    exit(0);
}

bool compare(char s[], char t[]) {
    int spos = 0;
    int tpos = 0;

    while (t[tpos] != '\0') {
        if (s[spos] == '\0') {
            return false;
        }

        if (toupper(s[spos]) != toupper(t[tpos])) {
            return false;
        }

        spos++;
        tpos++;
    }

    return true;
}

double numb() {
    double result = 0;

    skip_spaces();

    if (!isdigit(s[pos])) {
        error();
    }

    while (isdigit(s[pos])) {
        result *= 10;
        result += s[pos] - '0';
        pos++;
    }

    if (s[pos] == '.') {
        pos++;
        double multiplier = 0.1;

        if (!isdigit(s[pos])) {
            error();
        }

        while (isdigit(s[pos])) {
            result += multiplier * (s[pos] - '0');
            multiplier /= 10.0;
            pos++;
        }
    }

    return result;
}

double term() {
    
    double result = 0;
    skip_spaces();

    if (compare(s + pos, SIN)) {
        pos += 3;
        skip_spaces();
        
        if (s[pos] != '(') {
            error();
        }

        pos++;
        
        result = sin(expr());

        skip_spaces();
        
        if (s[pos] != ')') {
            error();
        }
        
        pos++;
    } else if (compare(s + pos, COS)) {
        pos += 3;
        skip_spaces();
        
        if (s[pos] != '(') {
            error();
        }

        pos++;

        result = cos(expr());
        
        skip_spaces();
        
        if (s[pos] != ')') {
            error();
        }

        pos++;
    } else if (s[pos] == '(') {
        pos++;
        result = expr();

        skip_spaces();

        if (s[pos] != ')') {
            error();
        }

        pos++;
    } else if (isdigit(s[pos])) {
        result = numb();
    } else {
        error();
    }

    return result;
}

double fact() {
    double result = term();

    skip_spaces();

    while (s[pos] == '*' || s[pos] == '/') {
        skip_spaces();

        if (s[pos] == '*') {
            pos++;
            skip_spaces();

            result *= term();
            skip_spaces();

        } else if (s[pos] == '/') {
            pos++;
            skip_spaces();
            
            result /= term();
            skip_spaces();
        }
    }

    return result;
}

double expr() {
    skip_spaces();

    if (s[pos] == ')') {
        error();
    }

    double result = fact();

    skip_spaces();

    while (s[pos] == '+' || s[pos] == '-') {
        skip_spaces();

        if (s[pos] == '+') {
            pos++;
            skip_spaces();

            result += fact();
            skip_spaces();

        } else if (s[pos] == '-') {
            pos++;
            skip_spaces();
            
            result -= fact();
            skip_spaces();
        }
    }

    skip_spaces();

    if (s[pos] != '\0' && s[pos] != ')') {
        error();
    }

    return result;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    gets(s);

    printf("%.5lf\n", expr());

    return 0;
}
                