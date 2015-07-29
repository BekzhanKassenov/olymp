#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	double a, b, c;

	cin >> a >> b >> c;

	if (a != 0)
		{
			double d = b * b - 4 * a * c;

			if (d < 0)
				{
					cout << 0;
					return 0;
				}

			double x1 = (-b + sqrt(d)) / (2 * a);
			double x2 = (-b - sqrt(d)) / (2 * a);

			if (x1 == x2)
				printf("1\n %.6lf", x1);
			else	
				printf("2\n%.6lf\n%.6lf", min(x1, x2), max(x1, x2));
			return 0;
		}

	if (a == 0)
		{
			if (b == 0)
				{
					if (c == 0)
						{
							cout << -1;
						}
					else
						{
							cout << 0;
						}
				}
			else
				printf("1\n%.6lf", -(c / b));
		}

	return 0;
}
