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

	long long operator * (point a)
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

	long long ans = 0;

	for (int i = 1; i < n - 1; i++)
		{
			ans += (a[i] - a[0]) * (a[i + 1] - a[0]);
		}

	ans = abs(ans);

	if (ans & 1)
		printf("%lld.5", ans >> 1);
	else
		printf("%lld.0", ans >> 1);

	return 0;	
}
