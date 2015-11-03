#include <iostream>
#include <cstdio>
#include <memory.h>

using namespace std;

void apply(int a[6], const int perm[6]) {
    static int buf[6];

    for (int i = 0; i < 6; i++) {
        buf[perm[i]] = a[i];
    }

    memcpy(a, buf, sizeof(a[0]) * 6);
}

const int rotate1[] = {1, 4, 2, 0, 3, 5};
const int rotate2[] = {5, 1, 0, 3, 2, 4};
const int rotate3[] = {0, 5, 1, 2, 4, 3};

bool equal(int a[6], int b[6]) {
    for (int i = 0; i < 6; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    
    return true;
}

int go(int a[6], int b[6], int d = 0) {
    if (d > 4) {
        return 0;
    }

    if (equal(a, b)) {
        return 1;
    }

    int ans = 0;
    swap(a[1], a[3]);
    if (equal(a, b)) {
        ans = 2;
    }

    swap(a[1], a[3]);

    swap(a[0], a[4]);
    if (equal(a, b)) {
        ans = 2;
    }

    swap(a[0], a[4]);

    swap(a[2], a[5]);
    if (equal(a, b)) {
        ans = 2;
    }

    swap(a[2], a[5]);

    int temp;

    for (int i = 0; i < 4; i++) {
        apply(a, rotate1);

        temp = go(a, b, d + 1);

        if (temp == 1) {
            return 1;
        }

        if (temp == 2) {
            ans = 2;
        }
    }

    for (int i = 0; i < 4; i++) {
        apply(a, rotate2);

        temp = go(a, b, d + 1);

        if (temp == 1) {
            return 1;
        }

        if (temp == 2) {
            ans = 2;
        }
    }

    for (int i = 0; i < 4; i++) {
        apply(a, rotate3);

        temp = go(a, b, d + 1);

        if (temp == 1) {
            return 1;
        }

        if (temp == 2) {
            ans = 2;
        }
    }

    return ans;
}

int a[6], b[6];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    for (int i = 0; i < 6; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < 6; i++) {
        scanf("%d", &b[i]);
    }

    printf("%d\n", go(a, b));

    return 0;
}
