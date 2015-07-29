#include <iostream>
#include <cstdio>

using namespace std;

int sbf(int n)
{
	switch (n)
	{
		case 1: return 0;
		case 2: return 1;
		case 3: return 2;
		case 4: return 9;
		case 5: return 44;
		case 6: return 265;
		case 7: return 1854;
		case 8: return 14833;
		case 9: return 133496;
	}

}

int fact(int n)
{
	if ((n==1) || (n==0))
		return 1;
	return n*fact(n-1);
}


int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	int k;
	cin>>n>>k;
	if (n==k) 
		{
			cout<<1;
			return 0;
		}
	int ans=1;
	for (int i=k+1;i<=n;i++)
		ans*=i;
	ans/=fact(n-k);
	ans*=sbf(n-k);
	cout<<ans;
	return 0;
}
