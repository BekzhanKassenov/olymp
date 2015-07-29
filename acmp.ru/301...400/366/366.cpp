#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

const int maxn = 13;

int n, a[13], b[13], na, nb, k, k1;
map <int, int> mapa, mapb;

void build(map <int, int>& Map, int arr[], int len) {
    for (int mask = 0; mask < (1 << len); mask++) {
        int sum = 0;

        for (int i = 0; i < len; i++) {
            if (mask & (1 << i))
                sum += arr[i];
            else
                sum -= arr[i];
        }

        Map[sum] = mask;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &k);

    scanf("%d", &k1);

    if (n == 1) {
        int x;
        scanf("%d", &x);
        
        if (k1 + x == k) {
            printf("%d+%d=%d\n", k1, x, k);
        } else if (k1 - x == k) {
            printf("%d-%d=%d\n", k1, x, k);
        } else {
            puts("No solution");
        }

        return 0;
    }

    n--;
    na = n / 2;
    nb = n - na;

    for (int i = 0; i < na; i++)
        scanf("%d", a + i);

    for (int i = 0; i < nb; i++)
        scanf("%d", b + i);

    build(mapa, a, na);
    build(mapb, b, nb);

    for (map <int, int> :: iterator it = mapa.begin(); it != mapa.end(); it++) {
        int suma = it -> first;
        int maska = it -> second;

        if (mapb.count(k - suma - k1)) {
            int maskb = mapb[k - suma - k1];

            printf("%d", k1);

            for (int i = 0; i < na; i++) {
                if (maska & (1 << i))
                    putchar('+');
                else
                    putchar('-');

                printf("%d", a[i]);
            }

            for (int i = 0; i < nb; i++) {
                if (maskb & (1 << i))
                    putchar('+');
                else
                    putchar('-');

                printf("%d", b[i]);
            }

            printf("=%d", k);
            return 0;
        }
    }

    puts("No solution");

    return 0;

}
