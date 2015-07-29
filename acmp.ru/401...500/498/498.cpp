#include <iostream>
#include <cstdio>

using namespace std;

int n, k;
bool used[10];
int a[10];

int go(int pos) {
    if (pos == n)
        return 1;

    int l = 0, r = 0, res = 0;
    
    if (pos == 0) {
        r = n - 1;
    } else {
        l = max(a[pos - 1] - k, 0);
        r = min(a[pos - 1] + k, n - 1);
    }

    for (int i = l; i <= r; i++) {
        if (!used[i]) {
            a[pos] = i;
            used[i] = true;
            res += go(pos + 1);
            used[i] = false;
        }
    }

    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d\n", &n, &k);

    printf("%d\n", go(0));

    return 0;
}
