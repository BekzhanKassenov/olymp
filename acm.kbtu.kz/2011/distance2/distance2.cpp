#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()

{
freopen("distance2.in","r",stdin);
freopen("distance2.out","w",stdout);
double x,y,x1,x2,y1,y2;
scanf("%lf%*c%lf%*c%lf%*c%lf%*c%lf%*c%lf",&x,&y,&x1,&y1,&x2,&y2);
fclose(stdin);
double kos=abs((x2-x)*(y1-y)-(y2-y)*(x1-x));
double rez=kos/sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
printf("%.6f",rez);
fclose(stdout);
return 0;
}

