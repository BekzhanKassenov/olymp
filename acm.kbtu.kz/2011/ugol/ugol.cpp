#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
freopen("angle2.in","r",stdin);
freopen("angle2.out","w",stdout);
double x1;
double x2;
double y1;
double y2;
cin>>x1>>y1>>x2>>y2;
fclose(stdin);
double skal=x1*x2+y1*y2;
const double pi=3.1415926;
if (skal==0)
{
cout<<pi/2;
fclose(stdout);
return 0;
}
double kos=x1*y2-x2*y1;
double rez=abs(atan2(kos,skal));
cout<<rez;
fclose(stdout);
return 0;
}
