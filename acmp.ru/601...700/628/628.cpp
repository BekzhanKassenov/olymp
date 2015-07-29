#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAXN = 15010;

int a[MAXN];
int n, x, y;
int _x0, _x1;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d%d", &x, &y);
        a[i] = x;
    }

    _x0 = a[0];
    _x1 = a[1];

    sort(a, a + n);

    if (_x0 > _x1) {
        swap(_x0, _x1);
    }

    int mid = n / 2;

    int result = a[mid];    

    if (result < _x0) {
        result = _x0;
    } else if (result > _x1) {
        result = _x1;
    }

    printf("%d\n", result);

    return 0;
}
