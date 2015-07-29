#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

inline double sqr(double x) {
	return x * x;
}

inline void get_line(int x, int y, int _x, int _y, double& a, double& b, double& c) {
	a = _y - y;
	b = x - _x;
	c = y * _x - x * _y;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int x[3], y[3];

	cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2];

	int _x, _y;

	cin >> _x >> _y;

	double a, b, c;

	double ans = 1e14;

	for (int i = 0; i < 3; i++) {
		get_line(x[i], y[i], x[(i + 1) % 3], y[(i + 1) % 3], a, b, c);

		if (x[i] != x[(i + 1) % 3] || y[i] != y[(i + 1) % 3])
			ans = min(ans, abs(a * _x + b * _y + c) / sqrt(sqr(a) + sqr(b)));
		else
			ans = min(ans, sqrt(sqr(_x - x[i]) + sqr(_y - y[i])));	
	}

	printf("%.10lf", ans);

	return 0;
}
