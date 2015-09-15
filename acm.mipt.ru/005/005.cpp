#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 100010;

char s[MAXN];
int pos;

void skip() {
    while (s[pos] && s[pos] == ' ') {
        pos++;
    }
}

int readInt() {
    bool flag = false;

    if (s[pos] == '-') {
        flag = true;
        pos++;
    }

    int res = 0;

    while (isdigit(s[pos])) {
        res *= 10;
        res += s[pos] - '0';
        pos++;
    }

    if (flag) {
        res *= -1;
    }

    return res;
}

double parse() {
    skip();

    if (s[pos] == '(') {
        pos++; // for (
        double _left = parse();
        
        skip();
        
        double _right = parse();
        pos++; // for )

        skip();
        return 0.5 * _left + 0.5 * _right;
    }

    double result = readInt();
    skip();

    return result;
}

int main() {
#ifdef Local    
    freopen("in", "r", stdin);
#endif
    gets(s);

    printf("%.2lf\n", parse());

    return 0;
}
