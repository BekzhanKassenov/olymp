#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 100010;

char rule[15][3];
char s[MAXN];
int next[MAXN], prev[MAXN];
int n, len;

bool gram(int pos) {
    if (pos == 0 || next[pos] == len + 1)
        return false;

    for (int i = 0; i < n; i++) {
        if (s[pos] == rule[i][0] && s[next[pos]] == rule[i][1])
            return true;
    }

    return false;
}

bool converse() {
    int pos = next[0];
    bool result = false;

    while (pos != len + 1) {
        while (gram(pos)) {
            next[prev[pos]] = next[next[pos]];
            prev[next[next[pos]]] = prev[pos];

            result = true;
            pos = prev[pos];
        }

        pos = next[pos];
    }

    return result;
}
                                       
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d\n", &n);

    for (int i = 0; i < n; i++)
        gets(rule[i]);

    gets(s + 1);
    len = strlen(s + 1);

    next[0] = 1;
    prev[len + 1] = len;

    for (int i = 1; i <= len; i++) {
        next[i] = i + 1;
        prev[i] = i - 1;
    }

    while (converse());
    
    for (int i = next[0]; i != len + 1; i = next[i]) {
        putchar(s[i]);
    }

    putchar('\n');
    return 0;
}
