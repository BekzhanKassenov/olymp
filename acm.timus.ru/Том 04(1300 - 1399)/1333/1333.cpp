#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>

using namespace std;

#define F first
#define S second
#define sqr(x) (x) * (x)

const double EPS = 1e-3;

int main()
{	
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	cin >> n;

	vector <pair <double, double> > cr(n);

	vector <double> r(n);

	for (int i = 0; i < n; i++)
		cin >> cr[i].F >> cr[i].S >> r[i];

	double cnt1 = 0, cnt = 0;;

	for (double x = 0; x <= 1; x += EPS)
		for (double y = 0; y <= 1; y += EPS)
			{
				bool flag = false;

				for (int i = 0; i < n && !flag; i++)
					{
						if (sqr(x - cr[i].F) + sqr(y - cr[i].S) <= sqr(r[i]))
							flag = true;
					}

			   if (flag)
			   	cnt1 += 1;

			   cnt += 1;
			}
	printf("%.10lf", (cnt1 * 100) / cnt);

	return 0;
}	
