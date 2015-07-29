#include <iostream>
#include <cstdio>
#include <cmath>

int sqr(int n) 
{
	return n*n;
}

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int x1,x2,y1,y2,r1,r2;
	cin>>x1>>y1>>r1;
	cin>>x2>>y2>>r2;
	double rt=sqrt(double(sqr(x1-x2)+sqr(y2-y1)));
	if ((rt>double(r1+r2)) || (rt<abs(double(r1-r2)))) cout<<"NO";
	else cout<<"YES";
	return 0;

}
