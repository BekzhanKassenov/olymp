#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int k, ans = (int)1e9, answ, ansh;

int beaty(int h, int w) {
    return abs(h - w) + k - h * w;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &k);
    
    for (int h = 1; h <= k; h++) {
        int w = k / h;

        if (beaty(w, h) < ans) {
            ans = beaty(w, h);
            answ = w;
            ansh = h;
        }
    }

    printf("%d %d\n", answ, ansh);

    return 0;
}
