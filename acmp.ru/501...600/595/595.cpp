#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 50010;

char s[MAXN], t[MAXN];
int n;
int z[2 * MAXN];

struct proxy {
    const char *s, *t;
    int slen, tlen;

    proxy(char s[], char t[]) {
        this->s = s;
        this->t = t;
        slen = strlen(s);
        tlen = strlen(t);
    }

    char operator [](int pos) const {
        if (pos < tlen) {
            return t[pos];
        }

        if (pos == tlen) {
            return '#';
        }

        pos -= tlen + 1;
        return s[pos];
    }

    int size() const {
        return slen + tlen + 1;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    gets(s);
    gets(t);

    n = strlen(s);

    if (strcmp(s, t) == 0) {
        puts("Yes");
        puts("0");
        return 0;
    }

    proxy p(s, t);

    z[0] = 1;
    for (int i = 1, l = 0, r = 0; i < p.size(); i++) {
        if (i <= r) {
            z[i] = min(z[i - l], r - i + 1);
        }

        while (i + z[i] < p.size() && p[z[i]] == p[i + z[i]]) {
            z[i]++;
        }

        if (i + z[i] - 1 > r) {
            l = i, r = i + z[i] - 1;
        }
    }

    /*
    for (int i = 0; i <= 2 * n; i++) {
        cout << p[i];
    }
    cout << endl;
    for (int i = 0; i <= 2 * n; i++) {
        cout << z[i];
    }
    cout << endl;
    */

    for (int k = 0; k < n && s[k] == t[n - 1 - k]; k++) {
        int idx = k + 1;
        if (z[n + idx + 1] == n - k - 1) {
            puts("Yes");
            printf("%d\n", k + 1);
            return 0;
        }
    }

    puts("No");

    return 0;   
}
