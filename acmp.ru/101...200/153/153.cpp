#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int n, m;
int a[15];

long long cursum;
int curcnt;

int ans = 100;

void go(int pos) {
    if (cursum == m) {
        ans = min(ans, curcnt);
        return;
    }

    if (pos == n) {
        return;
    }

    go(pos + 1);

    for (int i = 0; i < 2; i++) {
        cursum += a[pos];
        curcnt++;
        go(pos + 1);
    }

    cursum -= 2 * a[pos];
    curcnt -= 2;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    scanf("%d%d", &m, &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    long long total = 0;
    for (int i = 0; i < n; i++) {
        total += a[i] * 2;
    }

    if (total < m) {
        puts("-1");
        return 0;
    }

    go(0);

    if (ans == 100) {
        puts("0");
    } else {
        printf("%d\n", ans);
    }

	return 0;
}
