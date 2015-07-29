#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin>>n;
	if (n==0)
		{
			cout<<10;
			return 0;
		}
	int a[10];
	for (int i=0;i<10;i++)
		a[i]=0;
	for (int i=9;i>=2;i--)
	{
		while (n%i==0)
		{
			a[i]++;
			n/=i;
		}
	}
	if (n!=1)
		{
			cout<<-1;
			return 0;
		}
	for (int i=2;i<10;i++)
		for (int j=1;j<=a[i];j++)
			cout<<i;
	return 0;  	

}
