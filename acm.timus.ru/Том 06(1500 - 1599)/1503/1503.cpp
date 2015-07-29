#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

const double INF = 1e23;

#define all(x) (x).begin(), (x).end()

double f(vector <double> coeff, double x) {
    double res = 0;

    for (int i = coeff.size() - 1; i >= 0; i--) {
        res *= x;
        res += coeff[i];
    }

    return res;
}

double bin_search(double l, double r, vector <double> coeff) {
    for (int i = 0; i < 50; i++) {
        double mid = (l + r) >> 1;

        if (f(mid) > 0)
            r = mid
    }
}

vector <double> solve(vector <double> coeff) {
    vector <double> res;

    if (coeff.size() == 2u)
        res.push_back(-coeff[1] / coeff[0]);
    else {
        vector <double> coeff1;

        for (size_t i = 0; i < coeff.size() - 1; i++) {
            coeff1[i] = coeff[i] * (coeff.size() - i);
        }

        vector <double> roots = solve(coeff1)

        if (!roots.empty()) {
            double x = bin_search(-INF, roots[0], coeff);

            if (f(coeff, x) == 0)
                res.push_back(x);


            for (int i = 1; i < (int)roots.size() - 1; i++) {
                x = bin_search(roots[i], roots[i + 1], coeff);

                if (f(coeff, x) == 0)
                    res.push_back(x);
            }

            x = bin_search(res.back(), INF, coeff);
            
            if (f(coeff, x) == 0)
                res.push_back(x);
        }
    }

    sort(all(res));

    return res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    int n;
    cin >> n;

    vector <double> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector <double> res = solve(a);

    for (size_t i = 0; i < res.size(); i++)
        printf("%.10lf\n", res[i]);

    return 0;
}
