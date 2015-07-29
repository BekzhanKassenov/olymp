#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;

	cin >> n;

	vector <double> a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a.begin(), a.end());

	double now;

	cin >> now;

	for (int i = 0; i < n; i++)
		{
			double tmp = (now + a[i]) / 2;

			if (tmp > now)
				now = tmp;
		}

	printf("%.6lf", now);
	return 0;
}
