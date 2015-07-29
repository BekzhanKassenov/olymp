#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

double sqr(double x)
{
	return x*x;
}

double dist(double x1, double y1, double x2, double y2)
{
	return sqrt(sqr(x2-x1)+sqr(y2-y1));
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin>>n;
	int x,y,x1,y1;
	x=y=0;
	double ans=0;
	for (int i=0;i<n;i++)
		{
			cin>>x1>>y1;
			ans+=dist(x,y,x1,y1);
			x=x1;
			y=y1;
		}
	ans+=dist(x1,y1,0,0);
	printf("%.3lf",ans);
	return 0;
}
