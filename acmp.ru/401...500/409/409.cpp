#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;

	cin >> n;

	double ans = 0;

	int a;

	cin >> a;

	int tmp;

	for (int i = 1; i < n; i++)
		{
			cin >> tmp;
			ans += (double(tmp + a) / 2.0);
			a = tmp;
		}

	ans /= double(n - 1);

	printf("%.6lf", ans);

	return 0;
}
