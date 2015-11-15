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
const int MAXN = 110;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

char sub(char a, char b) {
    return ((a - 'A') - (b - 'A') + 26) % 26 + 'A';
}

char add(char a, char b) {
    return ((a - 'A') + (b - 'A')) % 26 + 'A';
}

void getKey(char P[], char C[], int textlen, char K[], int keylen) {
    if (keylen > textlen) {
        return;
    }

    for (int i = 0; i < keylen; i++) {
        K[i] = sub(C[i], P[i]);
    }

    K[keylen] = '\0';
}

void encrypt(char P[], char C[], int textlen, char K[], int keylen) {
    for (int i = 0; i < min(keylen, textlen); i++) {
        C[i] = add(P[i], K[i]);
    }

    for (int i = keylen; i < textlen; i++) {
        C[i] = add(P[i], C[i - keylen]);
    }

    C[textlen] = '\0';
}

char P[MAXN][MAXN], C[MAXN][MAXN];
char K[MAXN];
int len[MAXN];
int n;

bool checkLen(int keylen) {
    int pos = -1;
    for (int i = 0; i < n; i++) {
        if (len[i] >= keylen) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        return false;
    }

    getKey(P[pos], C[pos], len[pos], K, keylen);

    static char tempC[MAXN];
    for (int i = 0; i < n; i++) {
        encrypt(P[i], tempC, len[i], K, keylen);

        if (strcmp(tempC, C[i]) != 0) {
            return false;
        }
    }

    return true;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    while (scanf("%d\n", &n) == 1 && n != 0) {
        for (int i = 0; i < n; i++) {
            scanf("%s\n%s", P[i], C[i]);
            len[i] = strlen(P[i]);
        }

        bool found = false;
        for (int i = 1; i <= 100; i++) {
            if (checkLen(i)) {
                found = true;
                break;
            }
        }

        if (found) {
            puts(K);
        } else {
            puts("Impossible");
        }
    }
    
    return 0;
}
