#include <iostream>
#include <cstdio>

using namespace std;

int absm(int a)
{
	if (a<0) return -a;
	return a;
}

int kos(int x1,int y1,int x2,int y2)
{
	return x1*y2-x2*y1;
}

bool intr(int x,int y,int x1,int y1,int x2,int y2,int x3,int y3)
{
	if (absm(kos(x1-x2,y1-y2,x3-x2,y3-y2))==absm(kos(x1-x,y1-y,x2-x,y2-y))+absm(kos(x2-x,y2-y,x3-x,y3-y))+absm(kos(x3-x,y3-y,x1-x,y1-y)))
		return true;
	return false;
			
}


int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int x,y,x1,y1,x2,y2,x3,y3;
	cin>>x1>>y1;
	cin>>x2>>y2;
	cin>>x3>>y3;
	cin>>x>>y;
	if (intr(x,y,x1,y1,x2,y2,x3,y3))
		{
			cout<<"In";
		}
	else cout<<"Out";
	return 0;
}
