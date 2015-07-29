#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 1000010;

int n, mem[2 * maxn], *cnt, cur;
char s[maxn];
long long ans;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    scanf("%d\n", &n);
    gets(s);
    cnt = mem + maxn;
    cnt[0] = 1;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'a')
            cur++;
        else
            cur--;

        ans += cnt[cur];
        cnt[cur]++;
    }

    printf("%I64d\n", ans);

    return 0;
}
