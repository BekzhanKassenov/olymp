#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
freopen("invkth.in","r",stdin);
freopen("invkth.out","w",stdout);
int x,k,n;
cin>>n>>k>>x;
for (int i=x-k+1;i<=x;i++)
cout<<i<<" ";
for (int i=x+1;i<=x+n-k;i++)
cout<<i<<" ";
return 0;
}
