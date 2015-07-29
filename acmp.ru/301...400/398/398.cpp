#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   int x;
   cin>>x;
   int ans=0;
	for (int i=x; i>0; i--)
      for (int j=i; j>0; j--)
      	{
			  if (i+j>=x) continue;
           for (int k=j; k>0; k--)
               if (x-i-j-k>0 && x-i-j-k<=k) 
   	         	ans++;
   	   }
   cout<<ans;
   return 0;
}
