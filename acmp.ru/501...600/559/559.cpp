#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cassert>
#include <cmath>

using namespace std;

const double PI = acos(-1.0);

double l, r, n;

double sqr(double r) {
 	return r * r;
}

double segment_area(double len) {
    double x = sqrt(sqr(r) - sqr(r - len));
    double sinhalf = x / r;
    double alpha = 2 * asin(sinhalf);
    double sector = sqr(r) * alpha / 2.0;
    double triangle = (r - len) * x;
    return sector - triangle;
}

double pref_area(double len) {
    if (len <= r) {
        return segment_area(len);
    } else if (len <= l + r) {
        double area = PI * sqr(r) / 2.0;
        len -= r;

        area += len * 2 * r;
        
        return area;
    } else {
        double area = PI * sqr(r) / 2.0;
        area += l * 2 * r;
        len -= r + l;

        area += PI * sqr(r) / 2.0 - segment_area(r - len);

        return area;
    }

    return 0;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    cin >> l >> r >> n;

	double part = PI * sqr(r) + l * (2 * r);
	part /= (n + .0);

    cout << fixed << setprecision(6);
    
    for (int i = 1; i < n; i++) {
        double area = part * i;

        double left = 0, right = l + r + r;

        for (int j = 0; j < 50; j++) {
            double mid = (left + right) / 2;

            if (pref_area(mid) < area) {
                left = mid;
            } else {
                right = mid;
            }
        }

        cout << left << endl;
    }

	return 0;
}
