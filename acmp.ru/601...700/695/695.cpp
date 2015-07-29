#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

char a, b, c, d;

int dx[] = {1,  1, -1, -1, 2,  2, -2, -2};
int dy[] = {2, -2,  2, -2, 1, -1,  1, -1};

int solve(int aa, int bb) {
    if (aa == c && bb == d)
        return 0;

    if (abs(aa - c) == abs(bb - d))
        return 1;

    return 2;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (scanf("%c%c %c%c\n", &a, &b, &c, &d) == 4) {

        printf("%c%c %c%c ", a, b, c, d);
        a -= 'A';
        b -= '0' + 1;

        c -= 'A';
        d -= '0' + 1;

        if ((c + d) % 2 == 1) {
            puts("-1");
            continue;
        }

        if (a == c && b == d) {
            puts("0");
            continue;
        }

        if ((a + b) % 2 == 1) {
            int ans = 10;

            for (int i = 0; i < 8; i++) {
                int ta = a + dx[i];
                int tb = b + dy[i];

                if (ta >= 0 && ta < 9 && tb >= 0 && tb < 9)
                    ans = min(ans, solve(ta, tb) + 1);
            }

            printf("%d\n", ans);
        } else {
            printf("%d\n", solve(a, b));
        }
    }

    return 0;
}
