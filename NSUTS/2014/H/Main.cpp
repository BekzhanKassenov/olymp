/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 200;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct Triple {
    Triple() : x(0), y(0), c(0) { }
    long long x, y, c;
};

char s[MAXN], t[MAXN], temp[MAXN];
int pos;

void make(char dest[], char source[]) {
    int last = 0;
    for (int i = 0; source[i]; i++) {
        if (source[i] != '=')
            dest[last++] = source[i];
        else {
            dest[last++] = '-';
            dest[last++] = '(';
        }
    }

    dest[last++] = ')';
}

Triple val(char s[]);
Triple expr(char s[]);
Triple term(char s[]);

Triple val(char s[]) {
    Triple res;

    if (s[pos] == 'x') {
        res.x = 1;
        pos++;
        return res;
    }            

    if (s[pos] == 'y') {
        res.y = 1;
        pos++;
        return res;
    }

    int num = 0;
    bool mn = false;

    if (s[pos] == '-') {
        pos++;
        mn = true;
    }

    while (isdigit(s[pos])) {
        num *= 10;
        num += s[pos] - '0';
        pos++;
    }

    if (mn)
        num *= -1;

    if (s[pos] == 'x') {
        res.x = num;
        pos++;
    } else if (s[pos] == 'y') {
        res.y = num;
        pos++;
    } else
        res.c = num;

    return res;
}

Triple expr(char s[]) {
    Triple res = term(s);
    
    while (s[pos] == '+' || s[pos] == '-') {
        char sign = s[pos];
        pos++;
        Triple temp = term(s);

        if (sign == '+') {
            res.x += temp.x;
            res.y += temp.y;
            res.c += temp.c;
        } else {
            res.x -= temp.x;
            res.y -= temp.y;
            res.c -= temp.c;
        }
    }

    return res;
}

Triple term(char s[]) {
    Triple res;

    if (isdigit(s[pos]) || s[pos] == 'x' || s[pos] == 'y') {
        Triple temp = val(s);

        if (s[pos] == '(') {
            pos++;
            Triple temp1 = expr(s);

            temp1.x *= temp.c;
            temp1.y *= temp.c;
            temp1.c *= temp.c;
            pos++;
            temp = temp1;
        }

        res = temp;
    } else if (s[pos] == '(') {
        pos++;
        res = expr(s);
        pos++;
    }

    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    gets(temp);
    make(s, temp);
    gets(temp);
    make(t, temp);

    Triple a = expr(s);
    pos = 0;
    Triple b = expr(t);

    if (a.x == 0)
        swap(a, b);

    //cout << a.x << ' ' << a.y << ' ' << a.c << endl;
    //cout << b.x << ' ' << b.y << ' ' << b.c << endl;

    double y = (b.x * a.c - b.c * a.x + .0) / (b.y * a.x - b.x * a.y + .0);
    double x = (-a.c - a.y * y) / a.x;

    printf("%.10lf\n%.10lf\n", x, y);

    return 0;
}
