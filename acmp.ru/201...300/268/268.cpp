#include <iostream>
#include <string>
#include <cstdio>
#include <vector>

using namespace std;

const int maxn = 5010;

char s[maxn];
int n, k;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d %d\n", &n, &k);

    gets(s);
    int ans = 0;

    for (int i = 0; i < n; i++) {
        int l = i, r = i, cnt = 0;

        while (l >= 0 && r < n && cnt <= k) {
            if (s[l] != s[r])
                cnt++;

            if (cnt <= k)
                ans++;

            l--, r++;
        }

        l = i, r = i + 1, cnt = 0;

        while (l >= 0 && r < n && cnt <= k) {
            if (s[l] != s[r])
                cnt++;

            if (cnt <= k)
                ans++;

            l--, r++;
        }
    }

    printf("%d", ans);

    return 0;   
}
