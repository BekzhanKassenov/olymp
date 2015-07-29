#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

struct point
{
	int x, y;

	point() {}

	point (int x, int y): x(x), y(y) {}

	point operator - (point a)
		{
			return point(x - a.x, y - a.y);
		}

	int operator * (point a)
		{
			return x * a.y - y * a.x;
		}

	void read()
		{
			scanf("%d%d", &x, &y);
		}
};

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;

	scanf("%d", &n);

	vector <point> a(n);

	for (int i = 0; i < n; i++)
		a[i].read();

	int ans = 0;

	for (int i = 1; i < n - 1; i++)
		{
			ans += (a[i] - a[0]) * (a[i + 1] - a[0]);
		}

	ans = abs(ans);

	if (ans % 2)
		printf("%d.5", ans >> 1);
	else
		printf("%d.0", ans >> 1);

	return 0;	
}
