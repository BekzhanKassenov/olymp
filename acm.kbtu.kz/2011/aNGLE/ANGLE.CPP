#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
   double x,y;
   const double pi=3.1415926535;
   freopen("angle1.in","r",stdin);
   cin>>x>>y;
   double rez;
   if (x>0 && y>=0)
     rez=atan2(y,x);
   if (x>0 && y<0)
     rez=atan2(y,x)+2*pi;
   if (x<0)
     rez=atan2(y,x)+pi;
   if (x==0 && y>0) 
     rez=pi/2;
   if  (x==0 && y<0)
     rez=(3*pi)/2;
   if (x==0 && y==0)
     rez=0;
   freopen("angle1.out","w",stdout);
   cout<<rez;
   fclose(stdout);
   fclose(stdin);
   return 0;
}
