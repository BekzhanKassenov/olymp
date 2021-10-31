#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define all(x) (x).begin(), (x).end()

int n;
long double c[10], C;

int bitcount(int mask) {
    int result = 0;

    while (mask > 0) {
        result += mask & 1;
        mask >>= 1;
    }
    
    return result;
}

void go(int mask, vector <long double>& res) {
    if (bitcount(mask) == 1) {
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                res.push_back(c[i]);
                return;
            }
        }
    }

    vector <long double> a, b;
    for (int submask = (mask - 1) & mask; submask > 0; submask = (submask - 1) & mask) {
        a.clear();
        b.clear();

        go(submask, a);
        go(mask ^ submask, b);

        for (size_t i = 0; i < a.size(); i++) {
            for (size_t j = 0; j < b.size(); j++) {
                res.push_back(a[i] + b[j]);
                res.push_back((a[i] * b[j]) / (a[i] + b[j]));
            }
        }
    }

    sort(all(res));
    res.resize(unique(all(res)) - res.begin());
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n >> C;;

    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    for (int mask = 0; mask < (1 << n); mask++) {
        vector <long double> res;
        go(mask, res);

        for (size_t i = 0; i < res.size(); i++) {
            if (abs(res[i] - C) <= 0.01) {
                puts("YES");
                return 0;
            }
        }
    }

    puts("NO");

    return 0;
}
