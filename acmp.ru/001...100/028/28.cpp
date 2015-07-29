#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int xp1,yp1,xp2,yp2;
	cin>>xp1>>yp1>>xp2>>yp2;
	int x,y;
	cin>>x>>y;
	if (xp1==xp2)
			cout<<2*xp1-x<<" "<<y;
	else
		cout<<x<<" "<<2*yp1-y;
	return 0;
}
