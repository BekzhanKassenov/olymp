#include <cstdio>

using namespace std;

int solve(int n) {
    if (n == 3)
        return 1;

    if (n < 3)
        return 0;

    int nval = (n >> 1) + (n & 1);

    int a = nval >> 1;
    int b = (nval >> 1) + (nval & 1);

    int oval = n >> 1;

    int aa = oval >> 1;
    int bb = (oval >> 1) + (oval & 1);

    if (a != aa || b != bb)
        return solve(oval) + solve(nval);

    //printf("%d %d\n", n, val);

    return 2 * solve(oval);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
                                                                                                          
    int n;
    scanf("%d", &n);

    printf("%d", solve(n));

    return 0;
}
