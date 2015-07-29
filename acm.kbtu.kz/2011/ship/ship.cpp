#include <iostream>
#include <cstdio>
#include <stack>
#define apr stack <int>

using namespace std;


int main()
{
freopen("ship.in","r",stdin);
freopen("ship.out","w",stdout);
int n,k,p;
cin>>n>>k>>p;
apr a [101];
int x,y;
int y1;
int s=0,maxs=0;
char z;
for (int i=0;i<n;i++)
{
	cin>>z>>x>>y;
	if (z=='+') 
		{
			a[x].push(y);
			s++;
			if (s>maxs) maxs=s;
		}	
	else 
		{
			if (a[x].empty())
				{
					cout<<"Error";
					return 0;
				}
			if (a[x].top()!=y)
				{
					cout<<"Error";
					return 0;
				}
			a[x].pop();
			s--;
		}
	if (s>p)
		{
			cout<<"Eroor";
			return 0;
		}

}
for (int i=1;i<=100;i++)
if (!a[i].empty())
	{
		cout<<"Error";
		return 0;
	}
cout<<maxs;
return 0;
}
