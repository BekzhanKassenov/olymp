#include <iostream>
#include <cstdio>

using namespace std;

int n, k, number;
bool used[13];
int num[13], f[13];

int fact(int n) {
    if (f[n])   
        return f[n];

    if (n == 0)
        return 1;

    return n * fact(n - 1);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &k);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (used[j]) {
                continue;
            }
            
            num[i] = j;
            int cnt_r = fact(n - i);

            if (number + cnt_r >= k) {
                break;
            }

            number += cnt_r;
        }
        
        used[num[i]] = true;
    }

    for (int i = 1; i <= n; i++)
        printf("%d ", num[i]);

    return 0;
}
