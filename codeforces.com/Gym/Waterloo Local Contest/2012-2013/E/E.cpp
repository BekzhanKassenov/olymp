#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()

double sqr(double a) {
    return a * a;
}

bool check(ll a, ll b, ll c) {
	return a + b > c && a + c > b && b + c > a;
}

double vol(double a, double b, double c, double x, double y, double z) {
    double X = b * b + c * c - x * x;
    double Y = a * a + c * c - y * y;
    double Z = a * a + b * b - z * z;

    return sqrt(sqr(2 * a * b * c) - sqr(a * X) - sqr(b * Y) - sqr(c * Z) + X * Y * Z) / 12;
}

ll a[6];

void solve() {
    for (int i = 0; i < 6; i++) {
        for (int j = i + 1; j < 6; j++) {
            for (int k = j + 1; k < 6; k++) {
                vector <ll> tops;
                for (int l = 0; l < 6; l++) {
                    if (l != i && l != j && l != k) {
                        tops.push_back(a[l]);
                    }
                }

                bool ans = false;
                ll b1 = a[i], b2 = a[j], b3 = a[k];
                sort(all(tops));
                do {
                    ll t1 = tops[0];
                    ll t2 = tops[1];
                    ll t3 = tops[2];

                    bool temp = check(b1, b2, b3) && check(t3, t2, b1) && check(t1, t2, b3) && check(t1, t3, b2);;
                    temp &= vol(t1, t2, t3, b1, b2, b3) > 0;
                    ans |= temp;
                    if (ans) {
                        cout << "YES" << endl;/*
                        cout << b1 << ' ' << b2 << ' ' << b3 << endl;
                        cout << t1 << ' ' << t2 << ' ' << t3 << endl;
                        */
                        return;
                    }
                } while (next_permutation(all(tops)) && !ans);
            }
        }
    }
    cout << "NO" << endl;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;
	cin >> n;

	while (n --> 0) {
		for (int i = 0; i < 6; i++) {
			cin >> a[i];
		}

		solve();
	}

	return 0;
}
