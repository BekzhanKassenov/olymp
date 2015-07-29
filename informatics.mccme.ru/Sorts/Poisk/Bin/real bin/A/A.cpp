#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const double EPS = 10E-15;

double pw(double a, int n)
{
	double k = a;
	for (int i = 2; i <= n; i++)
		a *= k;
	return a;
}

int main()
{
	double a;
	int n;
	cin >> a >> n;
	double l = 0, r = a;
	double m;
	while (fabs(l - r) >= EPS)
		{
			m = (l + r) / 2;
			double k = pw(m, n);
			if (k == a)
				break;
			if (k > a)
				r = m;
			else
				l = m;
		}
	printf("%.7lf", m);
	return 0;
}
