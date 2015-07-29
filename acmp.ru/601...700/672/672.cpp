#include <iostream>
#include <cstdio>

using namespace std;

int n, cnt, cur_last, minn_last;
char cur[20], minn[20];

void go(int pos, int sum, int mul) {
    if (pos == n) {
        if (sum == mul) {
            cnt++;
            minn[n] = '\0';

            if (cur_last == 0 || strcmp(minn, cur) < 0) {
                strcpy(cur, minn);
                cur_last = minn_last + 1;
            }

        }

        return;
    }

    for (int i = 1; i < 10; i++) {
        if (mul * i <= 90) {
            minn[minn_last++] = (i + 48);

            go(pos + 1, sum + i, mul * i);
            minn_last--;
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &n);

    if (n == 1)
        puts("10 0");
    else {
        go(0, 0, 1);
        printf("%d %s\n", cnt, cur);
    }

    return 0;
}

                                