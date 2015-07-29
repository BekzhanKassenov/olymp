#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	freopen("cyclic.in","r",stdin);
	freopen("cyclic.out","w",stdout);
	int n;
	cin>>n;
	int a[1001];
	int c[1001];
	bool used [1001];

	for (int i=1;i<=n;i++)
		{		
			cin>>a[i];
			used[i]=false;
		}

	int s0=0,s,uk=0,i,x0;

	do
		{
			i=1;
			while (used[i])
				i++;
			used[i]=true;
			x0=a[i];
			i=x0;
			i=a[i];
			used[i]=true;
			s=1;
			while (i!=x0)
				{
					i=a[i];
					used[i]=true;
					s++;
				}
			uk++;
			c[uk]=s;
			s0+=s;
		}
	while (s0!=n);
	
	for (i=uk;i>0;i--)
		{
			int maxm=0;
			for (int j=1;j<=i;j++)
				if (c[j]>c[maxm]) maxm=j;
			s=c[maxm];
			c[maxm]=c[i];	
			c[i]=s;
		}
	cout<<uk<<endl;
	for (i=1;i<=uk;i++)
		cout<<c[i]<<" ";
	return 0;
}
