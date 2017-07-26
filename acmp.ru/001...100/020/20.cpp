#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAXN = 1000010;

int n;
int a[MAXN];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    if (n == 1) {
        puts("1");
        return 0;
    }

    int ans = 0;
    int len = 0;

    auto start_new = [&] (int pos) {
        if (a[pos] == a[pos - 1]) {
            len = 1;
        } else {
            len = 2;
        }
    };

    start_new(1);
    ans = max(ans, len);

    for (int i = 2; i < n; i++) {
        if (a[i - 2] == a[i - 1] || a[i - 1] == a[i]) {
            start_new(i);
        } else if ((a[i - 2] > a[i - 1]) == (a[i - 1] < a[i])) {
            len++;
        } else {
            start_new(i);
        }

        //fprintf(stderr, "%d\n", len);

        ans = max(ans, len);
    }

    printf("%d\n", ans);

    return 0;    
}

