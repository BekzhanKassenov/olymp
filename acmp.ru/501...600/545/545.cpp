#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cmath>

using namespace std;

inline double sqr(double x) {
    return x * x;
}

double a, b, c, area;

double get_cos(double a, double b, double c) {
    return (sqr(a) + sqr(b) - sqr(c)) / (2.0 * a * b);
}

double check_area(double a, double b, double c) {
    if (get_cos(a, b, c) < 0) {
        return 0;
    }

    double h = (2 * area) / c;
    double x = sqrt(sqr(a) - sqr(h));
    double y = c - x;

    return max(h * x, h * y) / 2.0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> a >> b >> c;

    double p = (a + b + c) / 2.0;
    area = sqrt(p * (p - a) * (p - b) * (p - c));

    cout << fixed << setprecision(10);

    double ans = max(max(check_area(a, b, c), check_area(a, c, b)), check_area(b, c, a));

    cout << ans << endl;

    return 0;
}
