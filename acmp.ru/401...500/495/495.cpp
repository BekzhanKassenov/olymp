#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

inline double sqr(double x)
{
	return x * x;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, k;

	cin >> n;

	vector <pair <double, double> > a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i].first >> a[i].second;

   	cin >> k;

   	for (int i = 0; i < k; i++) {
   		 vector <pair <double, double> > tmp(n);

   		 for (int i = 0; i < n; i++) {
   		 	tmp[i].first = (a[i].first + a[(i + 1) % n].first) / 2;
   		 	tmp[i].second = (a[i].second + a[(i + 1) % n].second) / 2;
   		 }
   		 a = tmp;
   	}

   	double ans = 0;

   	for (int i = 0; i < n; i++)
   		ans += (sqrt(sqr(a[i].first - a[(i + 1) % n].first) + sqr(a[i].second  - a[(i + 1) % n].second)));

   	printf("%.10lf", ans);

   	return 0;
}

