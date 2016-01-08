#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)

typedef unsigned int uint;

uint n;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%u", &n);

    int l = -1, r = -1;

    for (int i = 0; i <= 31; i++) {
        if (n & (1u << i)) {
            if (l == -1) {
                l = r = i;
            } else {
                r++;
            }
        } else {
            if (l != -1) {
                break;
            }
        }   
    }

    uint mask = (1u << (r - l + 1)) - 1;
    mask <<= l;
    n ^= mask;
    n |= 1u << (r + 1);

    n |= (1u << (r - l)) - 1;

//    eprintf("%d %d\n", l, r);
    printf("%u\n", n);

    return 0;
}
