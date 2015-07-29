#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int n;
double t, x[25], y[25], r[25];

double sqr(double n) {
    return n * n;
}

double solve(int i, int j) {
    double dist = sqrt(sqr(x[i] - x[j]) + sqr(y[i] - y[j])) - r[i] - r[j];

    return dist / 2.0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%lf", &n, &t);

    for (int i = 0; i < n; i++) {
        scanf("%lf%lf%lf", x + i, y + i, r + i);
    } 

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++)
            t = min(t, solve(i, j));
    }

    printf("%.4lf", t);

    return 0;
}    
