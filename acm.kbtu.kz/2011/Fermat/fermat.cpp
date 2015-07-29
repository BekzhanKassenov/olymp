#include <iostream>
#include <cstdio>

using namespace std;

int step(int x,int n)
{
	int a=1;
	for (int i =1; i<=n; i++)
 		{	
  			a*=x;
 		}
	return a;
}

int main()
{
	freopen("fermat.in","r",stdin);
	freopen("fermat.out","w",stdout);
	int x,y,n;
	cin>>x>>y>>n;
	x=step(x,n);
	y=step(y,n);
	int a=x+y;
	int s;
	int k;
	int z=1;
	int minim=1000000000;
	int mz=1000000000;
	s=0;

	while (s<=a)
		{
			s=step(z,n);
			k=a-s;
			if (k<0)
				k*=(-1);
			if (k<minim) 
				{
					minim=k;
					mz=z;
				}
			z++;
		}
     	
	cout<<minim<<endl;	
	cout<<mz<<endl;
	return 0;
}
