/****************************************
**        Solution by NU PTZ 2016      **
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

int n;
char s[MAXN];

bool make(char* a, char* b) {
    int len = strlen(a) + 1;
    char first = 'a';
    char last = 'a';
    int delta = 0;

    for (int i = 0; i + 1 < len; i++) {
        if (a[i] == '>') {
            first = 'a' + n - 1;
            delta = -1;
            last = 'a';
            break;
        } else if (a[i] == '<') {
            first = 'a';
            last = 'a' + n - 1;
            delta = 1;
        }
    }

    b[0] = first;
    for (int i = 0; i + 1 < len; i++) {
        if (a[i] != '=') {
            first += delta;
        }

        if (!('a' <= first && first < 'a' + n)) {
            return false;
        }

        b[i + 1] = first;
    }

    int pos = len - 2;
    while (pos >= 0 && b[pos] == b[len - 1]) {
        pos--;
    }

    for (int i = len - 1; i > pos; i--) {
        b[i] = last;
    }

    b[len] = '\0';

    //  printf("%s %s %d\n", a, b, len);

    return true;
}

char bufS[MAXN], bufAns[MAXN];
char result[MAXN];

bool process(char buf[], int& lastBuf) {
    static bool firstPart = true;

    buf[lastBuf] = '\0';

    if (!make(bufS, bufAns)) {
        return false;
    }

    if (firstPart) {
        strcpy(result, bufAns);
        firstPart = false;
    } else {
        strcat(result, bufAns + 1);
    }

    lastBuf = 0;
    
    return true;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d\n", &n);
    gets(s);
    int len = strlen(s) + 1;

    char type = '=';
    for (int i = 0; i + 1 < len; i++) {
        if (s[i] != '=') {
            type = s[i];
            break;
        }
    }

    int lastBuf = 0;
    for (int i = 0; i + 1 < len; i++) {
        if (s[i] != '=' && s[i] != type) {
            if (!process(bufS, lastBuf)) {
                puts("-1");
                return 0;
            }

            if (type == '>') {
                type = '<';
            } else {
                type = '>';
            }
        }

        bufS[lastBuf++] = s[i];
    }

    if (!process(bufS, lastBuf)) {
        puts("-1");
        return 0;
    }

    puts(result);

    return 0;
}
