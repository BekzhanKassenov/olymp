#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
freopen("r2d2.in","r",stdin);
freopen("r2d2.out","w",stdout);
int x1,y1,x2,y2;
cin>>x1>>y1>>x2>>y2;
int a=y2-y1;
int b=x1-x2;
int c=-x1*(y2-y1)+y1*(x2-x1);
cout<<a<<" "<<b<<" "<<c;
return 0;
}

