#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 10000;

int T;
int n, a[MAXN], b[MAXN];
int t[MAXN + 1];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n);
        memset(t, 0, sizeof t);

        for (int i = 0; i < n; i++) {
            scanf("%d%d", &a[i], &b[i]);
            t[a[i] + 1]++;
            t[b[i] + 1]--;
        }

        for (int i = 1; i <= MAXN; i++) {
            t[i] += t[i - 1];
        }

        bool result = true;
        for (int i = 1; i <= MAXN; i++) {
            if (t[i] > 1) {
                t[i] = 0;
            } else if (t[i] == 0) {
                result = false;
                break;
            } 
        }

        for (int i = 1; i <= MAXN; i++) {
            t[i] += t[i - 1];
        }

        for (int i = 0; i < n; i++) {
            int sum = t[b[i]] - t[a[i]];

            if (sum == 0) {
                result = false;
            }
        }

        if (result) {
            puts("Accepted");
        } else {
            puts("Wrong Answer");
        }
    }


    return 0;
}
