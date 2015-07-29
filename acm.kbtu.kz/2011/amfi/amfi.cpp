#include <iostream>
#include <cstdio>

using namespace std;

const double pi=3.141592;

int main()
{
freopen("amfi.in","r",stdin);
freopen("amfi.out","w",stdout);
double r1,r,l,d;
int s=0;
cin>>r>>r1>>l>>d;
l=l/100;
d=d/100;
while (r1<=r-l)
{
s+=(int)((pi*r1)/d);
r1+=l;
}
cout<<s<<"\n";
return 0;
}
