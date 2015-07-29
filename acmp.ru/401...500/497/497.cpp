#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 110;

int n, k;
int size[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int curnum[MAXN], maxnum[MAXN], minnum[MAXN];

void findmax(int pos, int k) {
    if (pos == n) {
        if (k == 0 && maxnum[0] == -1) {
            memcpy(maxnum, curnum, n * sizeof(int));
        }

        return;
    }

    int left = n - pos;

    if (left * 2 > k || left * 7 < k)
        return;

    int end = 0;
    if (pos == 0)
        end = 1;

    for (int i = 9; i >= end; i--) {
        if (size[i] <= k) {
            curnum[pos] = i;
            findmax(pos + 1, k - size[i]);
            if (maxnum[0] != -1)
                return;
        }
    }
}

void findmin(int pos, int k) {
    if (pos == n) {
        if (k == 0 && minnum[0] == -1) {
            memcpy(minnum, curnum, n * sizeof(int));
        }

        return;
    }

    int left = n - pos;

    if (left * 2 > k || left * 7 < k)
        return;

    int start = 0;
    if (pos == 0)
        start = 1;

    for (int i = start; i < 10; i++) {
        if (size[i] <= k) {
            curnum[pos] = i;
            findmin(pos + 1, k - size[i]);
            
            if (minnum[0] != -1)
                return;
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &k);

    memset(maxnum, 255, sizeof maxnum);
    memset(minnum, 255, sizeof minnum);

    findmax(0, k);
    findmin(0, k);

    if (maxnum[0] == -1)
        puts("NO SOLUTION");
    else {
        for (int i = 0; i < n; i++)
            printf("%d", minnum[i]);
        putchar('\n');

        for (int i = 0; i < n; i++)
            printf("%d", maxnum[i]);
        putchar('\n');
    }

    return 0;
}
