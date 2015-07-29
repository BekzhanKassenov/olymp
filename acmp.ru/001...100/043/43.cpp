#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	char k;
	int n=0,ans=0;
	while (!feof(stdin))
		{
			k=getchar();
			if (k=='0')
			n++;
			else
				{
					ans=max(ans,n);
					n=0;
				}
		}
   cout<<ans;
   return 0;
}
