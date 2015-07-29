#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 12;

int n;
int na, nb;
char *a[MAXN], *b[MAXN];
char s[2 * MAXN][MAXN];
bool used[2 * MAXN];

bool ok(char *arr[], int pos) {
    for (int i = 0; i <= pos; i++) {
        if (arr[i][pos] != arr[pos][i]) {
            return false;
        }
    }

    return true;
}

bool go(int pos) {
    if (pos == 2 * n) {
        return true;
    }

    for (int i = 0; i < 2 * n; i++) {
        if (used[i]) {
            continue;
        }

        if (na < n) {
            a[na] = s[i];
            if (ok(a, na)) {
                na++;
                used[i] = true;

                if (go(pos + 1)) {
                    return true;
                }

                used[i] = false;
                na--;
            }
        }

        if (nb < n) {
            b[nb] = s[i];
            if (ok(b, nb)) {
                nb++;
                used[i] = true;

                if (go(pos + 1)) {
                    return true;
                }

                used[i] = false;
                nb--;
            }
        }
    }

    return false;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d\n", &n);

    for (int i = 0; i < 2 * n; i++) {
        gets(s[i]);
    }

    go(0);

    for (int i = 0; i < n; i++) {
        puts(a[i]);
    }

    puts("");

    for (int i = 0; i < n; i++) {
        puts(b[i]);
    }

    return 0;
}
