#include <cstdio>
#include <cstring>
#include <utility>

using namespace std;

const int MAXN = 300;

char mem1[MAXN], mem2[MAXN];
char *s = mem1, *t = mem2;
int n, m;
bool dp[MAXN][MAXN], calced[MAXN][MAXN];

bool equal(int a, int b) {
    //printf("%d %d\n", a, b);
    if (!a || !b) {
        if (!a && !b)
            return true;

        if (!a) {
            for (int i = 1; i <= b; i++) {
                if (t[i] != '*')
                    return false;
            }

            return true;
        }

        return false;
    }

    if (calced[a][b])
        return dp[a][b];

    calced[a][b] = true;

    if (t[b] == '?' || s[a] == t[b]) {
        dp[a][b] = equal(a - 1, b - 1);
        return dp[a][b];
    }

    if (t[b] == '*') {
        for (int i = a; i >= 0; i--) {
            dp[a][b] |= equal(i, b - 1);
        }

        return dp[a][b];
    }

    return false;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    gets(s + 1);
    gets(t + 1);

    n = strlen(s + 1);
    m = strlen(t + 1);

    for (int i = 1; i <= n; i++) {
        if (s[i] == '?' || s[i] == '*') {
            swap(s, t);
            swap(n, m);
            break;
        }
    }

    if (equal(n, m))
        puts("YES");
    else
        puts("NO");

    return 0;
}
