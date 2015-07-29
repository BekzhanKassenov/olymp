#include <iostream>
#include <cstdio>
#include <cassert>

using namespace std;

#define fullmask(x) ((1 << (x)) - 1)

const int MAXN = 100010;

int n, a[MAXN];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    return 0;
}
