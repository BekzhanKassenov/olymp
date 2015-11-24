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
const int MAXN = 10010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int T;
char mapping[26][27];
char s[MAXN];

bool vowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}

bool win(char s[], int who) {
    int len = strlen(s);

    if (len == 1) {
        if (who == 0) {
            return vowel(s[0]);
        }

        return !vowel(s[0]);
    }

    int half = (len + 1) / 2;
    char buf[half + 1];

    buf[half] = '\0';

    for (int i = 0; i + 1 < len; i += 2) {
        buf[i >> 1] = mapping[s[i] - 'a'][s[i + 1] - 'a'];
    }

    if (len & 1) {
        buf[half - 1] = s[len - 1];
    }   

    bool res = !win(buf, who ^ 1);

    if (len & 1) {
        buf[0] = s[0];
        int ptr = 1;
        for (int i = 1; i + 1 < len; i += 2) {
            buf[ptr++] = mapping[s[i] - 'a'][s[i + 1] - 'a'];
        }

        if (!win(buf, who ^ 1)) {
            res = true;
        }
    }

    return res;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d\n", &T);

    while (T--) {
        for (int i = 0; i < 26; i++) {
            gets(mapping[i]);
        }

        gets(s);

        if (win(s, 0)) {
            puts("Salah");
        } else {
            puts("Marzo");
        }
    }
    
    return 0;
}
