#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
freopen("twoseq.in","r",stdin);
freopen("twoseq.out","w",stdout);
int a[1000],b[1000],c[1000],l[1000],r[1000];
int n,k;
cin>>n>>k;

for (int i=0;i<n;i++)
	cin>>a[i];

int uk=0,d;
bool lg=true;
for (int i=0;i<n;i++)
	{
		cin>>b[i];
		lg=lg && (b[i]==a[i]);
	}

if (lg==true)
	{	
		cout<<0;
		return 0;
	}

if (b[0]>=a[0]) c[0]=b[0]-a[0];
else c[0]=b[0]+k-a[0];
r[0]=1;
l[0]=1;
		
for (int i=1;i<n;i++)
	{
		if (b[i]>=a[i]) d=b[i]-a[i];
		else d=b[i]+k-a[i];
		if (d==c[uk])
			r[uk]++;
		else 
			{
				uk++;
				c[uk]=d;
				l[uk]=r[uk-1]+1;
				r[uk]=l[uk];
			}
	}
cout<<uk+1<<endl;
for (int i=0;i<=uk;i++)
	cout<<l[i]<<" "<<r[i]<<" "<<c[i]<<endl;
return 0;	
}
