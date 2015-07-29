#include <iostream>
#include <cstdio>

using namespace std;

bool test(int k)
{
	bool a[10];
	
	for (int i=0;i<10;i++)
		a[i]=false;
	
	int c=k;
	int ans=0;
	
	while (c>0)
		{
			a[(c%10)]=true;
			c/=10;
		}

	for (int i=0;i<10;i++)
		if (a[i]==true) 
			ans++;
	if (ans>2) return false;
	return true;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin>>n;
	if (!test(n))
		{
			int i=1;
			while (1) 
				{
					if (test(n-i))
						{
							cout<<n-i;
							break;
						}
					if (test(n+i))
						{
							cout<<n+i;
							break;
						}
					i++;
				}
		}
  else cout<<n;
  return 0;
}
