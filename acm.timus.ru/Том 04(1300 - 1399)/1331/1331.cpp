#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

const double pi = 3.1415;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n, m;

	cin >> n >> m;

	double r;

	cin >> r;

	vector <double> x(m), y(m);

	for (int i = 0; i < m; i++)
		cin >> x[i] >> y[i];

	int _x, _y;

	for (int i = 0; i < n; i++)
		{
			cin >> _x >> _y;

			double ans = 1e14;

			for (int j = 0; j < m; j++)
				{
					double xx = (_x * 2 * pi) / 360;

					double xx1 = (x[j] * 2 * pi) / 360;

					double yy = ((y[j] - _y) * 2 * pi) / 360;

					double angle = acos(sin(xx) * sin(xx1) + cos(xx) * cos(xx1) * cos(yy));

					double tmp = r * angle;

					ans = min(ans, tmp);
				}

			printf("%.10f\n", ans);
		}

 	return 0;
}