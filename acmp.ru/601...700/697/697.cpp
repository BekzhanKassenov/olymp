#include <iostream>
#include <cstdio>

using namespace std;

int l, w, h, ans;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d%d", &l, &w, &h);

    ans = (2 * (l * h + w * h) + 15) / 16;

    printf("%d\n", ans);

    return 0;
}
