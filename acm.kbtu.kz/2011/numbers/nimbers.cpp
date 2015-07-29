#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
freopen("numbers.in","r",stdin);
freopen("numbers.out","w",stdout);
int n,k;
int s=0;
int s1=0,s2=0;
int s11=0, s22=0;
cin>>n;
for (int i=1;i<=n;i++)
{
cin>>k;
k= k % 3;
if (k==1) 
{
s11=s1;
s1=i;
}
if (k==2) 
{
s22=s2;
s2=i;
}
s+=k;
}

s=s % 3;
if (s==1) 
	{
		if (s1!=0) 
			{
				cout<<n-1<<"\n";
				for (int i=1;i<=n;i++)
					if (i!=s1) cout<<i<<" ";
			}
		else 
			{			
					cout<<n-2<<"\n";
					for (int i=1;i<=n;i++)
						if ((i!=s2) && (i!=s22)) cout<<i<<" ";
			} 
	}
if (s==2) 
	{
		if (s2!=0)
			{
				cout<<n-1<<"\n";
				for (int i=1;i<=n;i++)
					if (i!=s2) cout<<i<<" ";
			}
		else
			{
				cout<<n-2<<"\n";
				for (int i=1;i<=n;i++)
					if ((i!=s1) && (i!=s11)) cout<<i<<" ";
			}
	}
if (s==0)
	{ 
		cout<<n<<"\n";
		for (int i=1;i<=n;i++)
			cout<<i<<" ";
	}
return 0;
}
