#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin>>n;
	double x=0, y=0;
	int a,b;
	const double k=sqrt(2.0);
	for (int i=0;i<n;i++)
		{
			cin>>a>>b;
			if (a==1)
				y+=b;
			if (a==2)
				{
					y+=b/k;
					x+=b/k;
				} 
			if (a==3)
				x+=b;
			if (a==4)
				{
					x+=b/k;
					y-=b/k;
				}
			if (a==5)
				y-=b;
			if (a==6)
				{
					x-=b/k;
					y-=b/k;
				}
			if (a==7) 
				x-=b;
			if (a==8)
				{
					x-=b/k;
					y+=b/k;
				}
		}
	printf("%.3lf %.3lf",x,y);
	return 0;
}
