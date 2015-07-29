#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

#define sqr(x) (x) * (x)

double dist(double x, double y, double _x, double _y)
{
	return (sqrt(sqr(x - _x) + (sqr(y - _y))));
}

int main()
{
   #ifndef ONLINE_JUDGE
   	freopen("in", "r", stdin);
   #endif
	int n;

	double r;
	
	cin >> n >> r;
	
	double x, y, tmpx, tmpy, tmp1, tmp2;
	
	cin >> x >> y;
	
	tmpx = x;
	tmpy = y;
	
	double ans = 0;
	
	for (int i = 1; i < n; i++)	
		{
			cin >> tmp1 >> tmp2;
			
			ans += dist(tmpx, tmpy, tmp1, tmp2);
			
			tmpx = tmp1;
			tmpy = tmp2;
		}
	
	ans += dist(x, y, tmpx, tmpy);
	
	ans += 2 * 3.1415 * r;
	
	printf("%.2lf\n", ans);
	
	return 0;
}
