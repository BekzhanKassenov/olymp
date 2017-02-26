/****************************************
**     Solution by Bekzhan Kassenov    **
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
const int MAXN = 5010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

enum OP {
    XOR,
    AND,
    OR
};

int n, m;
map <string, int> Map = { {"?", 0} };

struct Term {
    int lhs;

    enum TYPE {
        NUMBER,
        EXPR
    };

    TYPE type;

    union {
        char val[MAXN];
        tuple <int, TYPE, int> expr_data;
    } data;

    void parseToken(char s[], int& sptr, char buf[]) {
        int buflen = 0;

        while (isspace(s[ptr])) {
            ptr++;
        }

        if (s[ptr] == '?') {
            ptr++;
            return "?";
        }

        while (isalpha(s[ptr])) {
            buf[buflen++] = s[ptr++];
        }
        buf[buflen] = '\n';
    }

    void parse(char s[]) {
        static char buf[1024];

        int ptr = 0;
        
        parseToken(s, ptr, buf);
        int num = Map.size();
        Map[string(buf)] = num;
        lhs = num;

        while (s[ptr] != ':') {
            ptr++;
        }

        ptr++; // =

        while (isspace(s[ptr])) {
            ptr++;
        }

        if (isdigit(s[ptr])) {
            type = NUMBER;
            for (int i = 0; i < n; i++) {
                data.val[i] = s[ptr++];
            }
        } else {
            type = EXPR;
            parseToken(s, ptr, buf);
            int l = Map[string(buf)];
            parseToken(s, ptr, buf);

            OP op;
            if (strcmp(buf, "XOR") == 0) {
                op = XOR;
            } else if (strcmp(buf, "OR") == 0) {
                op = OR;
            } else {
                op = AND;
            }

            parseToken(s, ptr, buf);
            int r = Map[string(buf)];

            data.expr_data = make_tuple(l, op, r);
        }
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    return 0;
}
