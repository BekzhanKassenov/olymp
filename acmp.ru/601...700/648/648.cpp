#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int n, a[110], sum;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    sort(a, a + n);

    for (int i = 0; i < n / 2; i++)
        sum -= a[i];

    for (int i = n / 2; i < n; i++)
        sum += a[i];

    printf("%d\n", sum);

    return 0;
}
