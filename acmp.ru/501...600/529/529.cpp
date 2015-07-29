#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	double x,y,x1,y1;
	cin>>x>>y>>x1>>y1;
	printf("%.5lf",sqrt( (x-x1)*(x-x1) + (y-y1)*(y-y1)));
	return 0;
}
