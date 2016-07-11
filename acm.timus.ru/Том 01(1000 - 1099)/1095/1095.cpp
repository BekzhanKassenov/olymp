#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int ans[7] = {4312, 3214, 4321, 4231, 2314, 3421, 4213};
char s[25];
int n;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d\n", &n);

    while (n--) {
        gets(s);
        int len = strlen(s);

        for (char c = '1'; c <= '4'; c++) {
            auto it = find(s, s + len, c);
            swap(*it, s[len - 1]);
            len--;
        }

        s[len] = '\0';

        if (s[0] == '0') {
            int pos = -1;
            for (int i = 0; i < len; i++) {
                if (s[i] != '0') {
                    pos = i;
                    break;
                }
            }

            if (pos == -1) {
                printf("4312%s\n", s);
                continue;
            } else {
                swap(s[0], s[pos]);
            }
        }

        int rem = 0;
        for (int i = 0; i < len; i++) {
            rem *= 10;
            rem += s[i] - '0';
            rem %= 7;
        }

        rem *= 10000;
        rem %= 7;
        rem = (7 - rem) % 7;
        
        printf("%s%d\n", s, ans[rem]);
    }

    return 0;
}
