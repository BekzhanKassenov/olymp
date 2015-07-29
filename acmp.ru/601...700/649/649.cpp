#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>

using namespace std;

int cnt[50], n, k;
long long ans;
char s[1000010]; 

int get_pos(char c) {
    if (isdigit(c))
        return c - '0';

    return 10 + c - 'a';
}

long long get_ans(int l, int r) {
    long long len = r - l;

    return len * (len + 1) / 2;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d %d\n", &n, &k);
    gets(s);

    int l = 0, r = 0;

    while (r < n) {
        int posr = get_pos(s[r]);
        cnt[posr]++;

        if (cnt[posr] > k) {
            while (l <= r && cnt[posr] > k) {
                ans += r - l;
                int posl = get_pos(s[l]);
                cnt[posl]--;
                l++;
            }
        }

        r++;
    }

    ans += get_ans(l, r);

    printf("%I64d\n", ans);

    return 0;
}
