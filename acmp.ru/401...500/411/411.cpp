#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	double a,b,c;
	cin>>a>>b>>c;
	double d=b*b-4*a*c;
	if (a==0)
		{
			if (b==0)
				{
					if (c==0)
						cout<<-1;
					else
						cout << 0;
					return 0;
				}	
			double x=-c/b;
			printf("1\n%.5lf",x);
			return 0;
		}
	if (d==0)
		{
			double x=-b/(2*a);
			printf("1\n%.5lf", x);
		}
	if (d>0)
		{
			double x1 = (-b+sqrt(d))/(2*a);
			double x2 = (-b-sqrt(d))/(2*a);
			printf("2\n%.5lf\n%.5lf",x1,x2);
		}
	if (d<0)
		cout << 0;
	return 0;

}
