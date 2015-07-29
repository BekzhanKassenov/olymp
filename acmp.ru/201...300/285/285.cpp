#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m;
    scanf("%d%d", &n, &m);

    int x, sum = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        
        if (x > m) {
            puts("no");
            return 0;
        }

        sum += x;
    }

    sum -= n - 1;

    if (sum >= m)
        puts("yes");
    else
        puts("no");

    return 0;
}
