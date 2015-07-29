#include <iostream>
#include <cstdio>

using namespace std;

int n, m, ans = 110;
char s[110];

int dot_cnt(char s[]) {
    int res = 0;

    for (int i = 0; s[i]; i++)
        res += s[i] == '.';

    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d %d\n", &n, &m);
    
    for (int i = 0; i < n; i++) {
        gets(s);

        ans = min(ans, dot_cnt(s));
    }

    printf("%d\n", ans);
}
