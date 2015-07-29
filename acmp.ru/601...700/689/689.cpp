#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;

int easy(ll n, int base) {
    static bool used[36];
    memset(used, false, sizeof used);
    int ans = 0;

    while (n) {
        if (!used[n % base])
            ans++;

        used[n % base] = true;
        n /= base;
        ans++;
    }

    return ans;
}

char letter(int n) {
    if (n < 10)
        return char(n + '0');

    return char ('A' + n - 10);
}

void print(ll n, int base) {
    static char s[100];
    static int last;
    last = 0;

    while (n) {
        s[last++] = letter(n % base);
        n /= base;
    }

    reverse(s, s + last);
    s[last] = '\0';

    printf("%d %s", base, s);
}

int t, anse, ans;
ll n;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &t);

    while (t --> 0) {
        scanf("%I64d", &n);

        ans = 2;
        anse = easy(n, 2);

        for (int i = 3; i <= 36; i++) {
            int k = easy(n, i);

            if (k < anse) {
                ans = i;
                anse = k;
            }
        }

        print(n, ans);
        puts("");
    }

    return 0;
}
