#include <iostream>
#include <cstdio>
#include <math.h>
#include <vector>

using namespace std;

#define PDD pair <double, double>
#define F first
#define S second
#define MP make_pair

double sqr(double x)
{
	return (x * x);
}

double dist(PDD p1, PDD p2)
{
	return (sqrt(sqr(p1.F - p2.F) + sqr(p2.S - p1.S)));
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;

	cin >> n;

	double p, c;

	cin >> c >> p;

	vector <PDD> a(n + 1);

	n++;

	for (int i = 0; i < n; i++)
		cin >> a[i].F >> a[i].S;

	for (int i = 0; i < n - 1; i++)
		{
			double cnt = 0;

			for (int j = 0; j < n; j++)
				{
					//cout << cnt << endl;

					cnt += dist(a[i], a[j]);
				}

			if (cnt * c <= p)
				{
					cout << "YES";
					return 0;
				}
		}

	cout << "NO";

	return 0;	
}
