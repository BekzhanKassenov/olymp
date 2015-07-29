#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 50010;

char s[MAXN], t[MAXN];
int n, ans = -1;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    gets(s);
    gets(t);

    n = strlen(s);

    int l = 0, r = n - 1;
    int dl = 1;

    for (int i = 0; i < n; i++) {
        if (s[l] != t[r]) {
            if (ans != -1) {
                puts("No");
                return 0;
            }

            ans = i;
            cout << ans << endl;
            l = n;
            dl = -1;
        }
        r--;
        l += dl;
    }

    if (ans == -1)
        ans = n;

    printf("%d\n", ans);

    return 0;   
}
