#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

double sqr(double x)
{
	return x * x;
}

double dist(double x, double y, double zx, double zy)
{
	return sqrt(sqr(x - zx) + (sqr(y - zy)));
}

int main()
{
	int n;
	cin >> n;

	vector <pair <double, double> > a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i].first >> a[i].second;

	int ak = 1, b = 2, c = 3;

	double ans = dist(a[0].first, a[0].second, a[1].first, a[1].second) + 
					 dist(a[1].first, a[1].second, a[2].first, a[2].second) + 
					 dist(a[0].first, a[0].second, a[2].first, a[2].second);

	for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
				for (int k = j + 1; k < n; k++)
					{
						double t = dist(a[i].first, a[i].second, a[j].first, a[j].second) + 
									  dist(a[j].first, a[j].second, a[k].first, a[k].second) + 
									  dist(a[k].first, a[k].second, a[i].first, a[i].second);
					   if (t < ans)
					   	{
					   		ans = t;
					   		ak = i + 1;
					   		b = j + 1;
					   		c = k + 1;
					   	}

					}
		}
	cout << ak << ' ' << b << ' ' << c;
	return 0;

}
