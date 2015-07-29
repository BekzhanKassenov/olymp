#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
int n,x,s=0;
cin>>n;
for (int i=1;i<=n;i++)
for (int j=1;j<=n;j++)
{
cin>>x;
if (x==1) s++;
}
cout<<s/2;
return 0;
}
