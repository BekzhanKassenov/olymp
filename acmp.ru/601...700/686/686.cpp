#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int maxn = 30010;

int n, a[maxn], arr[2][maxn], last[2];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    sort(a, a + n);

    for (int i = 0; i < n; i++) {
        arr[i & 1][last[i & 1]++] = a[i];
    }

    for (int i = 0; i < last[0]; i++)
        printf("%d ", arr[0][i]);

    for (int i = last[1] - 1; i >= 0; i--)
        printf("%d ", arr[1][i]);

    return 0;
}
