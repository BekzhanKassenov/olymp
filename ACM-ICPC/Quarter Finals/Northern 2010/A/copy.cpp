/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "acm"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;

template <typename T>
inline T sqr(T n) {
    return n * n;
}
int n, m;
int good[11], bad[11];

int from_base(int x, int base) {
    int ans = 0, cur = 1;
    int si = 1;
    if (x < 0) {
        x *= -1;
        si = -1;
    }
    while (x) {
        ans += (x % 10) * cur;
        cur *= base;
        x /= 10;
    }
    return ans * si;
}

int to_base(int x, int base) {
    int ans = 0, cur = 1;
    int si = 1;
    if (x < 0) {
        x *= -1;
        si = -1;
    }
    while (x) {
        ans += (x % base) * cur;
        cur *= 10;
        x /= base;
    }
    return ans * si;
}

bool cl(int x, int y) {
    if (y == 10)
        return true;
    while (x) {
        if ((x % 10) >= y) {
            return false;
        }
        x /= 10;
    }
    return true;
}

int feed(int x, int y, char op, int base) {
    int ans = 0;
    int _x = x, _y = y;
    if (base != 10) {
        _x = from_base(x, base);
        _y = from_base(y, base);
    } 
    if (op == '+') {
        ans = to_base(_x + _y, base);             
    }
    else if (op == '-') {
        ans = to_base(_x - _y, base);
    }
    else {
        ans = to_base(_x * _y, base);
    }
    return ans;
}

char ops[] = {'+', '-', '*'};

int parse(int a, int b, int c, int d, int e, int op1, int op2, int op3, int op4, int base) {
    
    if (cl(a, base) && cl(b, base) && cl(c, base) && cl(d, base) && cl(e, base)) {
        int t1 = feed(a, b, ops[op1], base);
        int t2 = feed(c, d, ops[op3], base); 
        if (op4 == 2) {
            int temp = feed(t2, e, ops[op4], base);
            return feed(t1, temp, ops[op2], base);    
        }         
        else {
            int temp = feed(t1, t2, ops[op2], base);
            return feed(temp, e, ops[op4], base);    
        }
    }
    else {
        return INF;
    }   
}

bool check(int a, int b, int c, int d, int e, int op1, int op2, int op3, int op4, int f) {
    for (int i = 1; i < n; i++) {
        if (parse(a, b, c, d, e, op1, op2, op3, op4, good[i]) != f)
            return false;
    }    
    for (int i = 0; i < m; i++) {
        if (parse(a, b, c, d, e, op1, op2, op3, op4, bad[i]) == f)
            return false;
    }
    return true;
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> good[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> bad[i];
    }
    

    for (int a = 0; a <= 50; a++) {
        for (int b = 0; b <= a; b++) {
            for (int c = 0; c <= 50; c++) {
                for (int d = 0; d <= c; d++) {
                    for (int e = 0; e < 10; e++) {
                        for (int op1 = 0; op1 < 3; op1++) {
                            for (int op2 = 0; op2 < 3; op2++) {
                                for (int op3 = 0; op3 < 3; op3++) {
                                    for (int op4 = 0; op4 < 3; op4++) {
                                        int f = parse(a, b, c, d, e, op1, op2, op3, op4, good[0]);
                                        if (f == INF) {
                                            continue;
                                        }
                                        if (check(a, b, c, d, e, op1, op2, op3, op4, f)) {
                                            printf("(%d%c%d)%c(%d%c%d)%c%d=%d", a, ops[op1], b, ops[op2], c, ops[op3], d, ops[op4], e, f);
                                            return 0;
                                        }
                                    }
                                }
                            }
                        }        
                    }    
                }
            }
        }
    }


    return 0;
}
