#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int kos(int x1,int y1,int x2,int y2)
{
	return x1*y2-x2*y1;
}

bool intr(int x,int y,int x1,int y1,int x2,int y2,int x3,int y3)
{
	int zn1,zn2,zn3;
	int z1=kos(x-x1,y-y1,x2-x1,y2-y1);
	int z2=kos(x-x2,y-y2,x3-x2,y3-y2);
	int z3=kos(x-x3,y-y3,x1-x3,y1-y3);
	if (z1>0)	zn1=1;
		else if (z1<0) zn1=-1;
			else zn1=0;
	if (z2>0)	zn2=1;
		else if (z2<0) zn2=-1;
			else zn2=0;
	if (z3>0)	zn3=1;
		else if (z3<0) zn3=-1;
			else zn3=0;
	if ((zn1==zn2 && zn1==zn3) && (zn1!=0))
		return true;
	return false;
			
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,x,y;
	cin>>x>>y;
	cin>>n;
	vector <bool> a(n,false);
	int x1,y1,x2,y2,x3,y3;
	int c=0;
	for (int i=0;i<n;i++)
		{
			cin>>x1>>y1>>x2>>y2>>x3>>y3;
			if (intr(x,y,x1,y1,x2,y2,x3,y3))
				{
					c++;
					a[i]=true;
				}
		}
	cout<<c<<endl;
	for (int i=0;i<n;i++)
		{
			if (a[i])
				cout<<i+1<< " ";
		}
	return 0;
}
