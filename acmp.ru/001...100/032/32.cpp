#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef vector <int> vc;

vc makev(long long a)
{
	vc ans;
	long long c=a;
	while (c>0)
		{
			ans.push_back(c%10);
			c/=10;
		}
	return ans;
}

long long stp(int a)
{
	long long ans=1;
	for (int i=0;i<=a;i++)
		ans*=10;
	return ans;
} 

long long makenmb(vc a)
{
	long long c=0;
	for (int i=a.size()-1;i>=0;i--)
		{
			c*=10;
			c+=a[i];	
		}
	return c;
}

vc sortup(vc a)
{
	vc z=a;
	for (int i=z.size()-1;i>=0;i--)
		{
			for (int j=0;j<i;j++)
					{
						if (z[j]>z[j+1])
						{
						int k=z[j];
						z[j]=z[j+1];
						z[j+1]=k;
						}
					}
		}
	return z;
}

vc sortdown(vc a)
{
	vc z=a;
	for (int i=z.size()-1;i>=0;i--)
		{
			for (int j=0;j<i;j++)
					{
						if (z[j]<z[j+1])
						{
						int k=z[j];
						z[j]=z[j+1];
						z[j+1]=k;
						}
					}
		}
	int m= z.size()-1;
	while (z[m]==0)
		m--;
	int k=z[m];
	z[m]=z[z.size()-1];
	z[z.size()-1]=k;
	return z;
}


int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	long long a,b;
	cin>>a>>b;
	int zn1=1,zn2=1;
	if (a>0)
		{
			vc t=makev(a);
			t=sortup(t);
			a=makenmb(t);
		}
	else
		{
			if (a<0)
				{
					a*=(-1);
					vc t=makev(a);
					t=sortdown(t);
					a=makenmb(t);
					a*=(-1);
				}
		}
	if (b>0)
		{
			vc t=makev(b);
			t=sortdown(t);
			b=makenmb(t);
		}
	else
		{
			if (b<0)
				{
					b*=(-1);
					vc t=makev(b);
					t=sortup(t);
					b=makenmb(t);
					b*=(-1);
				}
		}
	cout<<a-b;
	return 0;
}
