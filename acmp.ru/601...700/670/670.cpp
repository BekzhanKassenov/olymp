#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

bool check(int n) {
    static bool used[10];
    memset(used, false, sizeof used);

    while (n) {
        if (used[n % 10])
            return false;

        used[n % 10] = true;
        n /= 10;
    }

    return true; 
}

int n, i;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &n);

    while (n) {
        i++;

        if (check(i))
            n--;
    }

    printf("%d\n", i);

    return 0;
}
