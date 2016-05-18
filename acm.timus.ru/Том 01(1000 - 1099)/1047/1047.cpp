#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 3010;

int n;
double a_first, a_last;
double c[MAXN];
double upper[MAXN], mid[MAXN], lower[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    scanf("%lf%lf", &a_first, &a_last);

    for (int i = 1; i <= n; i++) {
        scanf("%lf", &c[i]);
    }

    for (int i = 2; i <= n; i++) {
        lower[i] = 0.5;
    }

    for (int i = 1; i <= n; i++) {
        mid[i] = -1.0;
    }

    for (int i = 1; i < n; i++) {
        upper[i] = 0.5;
    }

    c[1] -= 0.5 * a_first;
    c[n] -= 0.5 * a_last;

    for (int i = 1; i < n; i++) {
        double coeff = -lower[i + 1] / mid[i];
        
        lower[i + 1] += coeff * mid[i];
        mid[i + 1] += coeff * upper[i];
        c[i + 1] += coeff * c[i];
    }

    for (int i = n; i > 1; i--) {
        double coeff = -upper[i - 1] / mid[i];

        upper[i - 1] += coeff * mid[i];
        c[i - 1] += coeff * c[i];
    }

    printf("%.2lf\n", c[1] / mid[1]);

    return 0;
}
