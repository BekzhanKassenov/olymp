#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAXN = 100010;

inline int get_rand() {
    return ((rand() << 16) ^ rand());
}

int main() {
    int n = get_rand() % MAXN + 1;
    int m = get_rand() % MAXN + 1;
    
    printf("%d %d\n", n, m);
    
    for (int i = 0; i < m; i++) {
        if (get_rand() & 1) {
            int l = get_rand() % n;
            printf("1 %d %d %d\n", l + 1, l + get_rand() % (n - l), get_rand());
        } else {
            printf("2 %d\n", get_rand() % n + 1);
        }
    }
    
    return 0;
}
