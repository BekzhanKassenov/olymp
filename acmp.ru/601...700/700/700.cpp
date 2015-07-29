#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

ll res;
int n, v, k;
bool flag = false;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d%d", &n, &v, &k);

    for (int i = 0; i < n; i++) {
        if (v <= 0)
            flag = true;
        else {
            res += v;
            v -= k;
        }
    }

    printf("%s %I64d", flag ? "NO" : "YES", res);

    return 0;
}
