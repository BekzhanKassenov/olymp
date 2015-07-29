#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

double x[5];
double y[5];

double kos(int w,int e)
{
double xv1,yv1,xv2,yv2;
xv1=x[w]-x[e];
xv2=x[0]-x[e];
yv1=y[w]-y[e];
yv2=y[0]-y[e];
return xv1*yv2-xv2*yv1;
}


int main()
{
freopen("point.in","r",stdin);
freopen("point.out","w",stdout);

int n;
scanf("%d%*c%lf%*c%lf",n,x[0],y[0],"\n");
scanf("%lf%*c%lf",x[3],y[3],"\n");

x[4]=x[3];
y[4]=y[3];

scanf("%lf%*c%lf",x[2],y[2],"\n");

x[5]=x[2];
y[5]=y[2];

bool log=true;

for (int i=3;i<=n;i++)
{
	scanf("%lf%*c%lf",x[1],y[1],"\n");
    	if (kos(1,2)*kos(2,3)<0)
    	  {
		log=false;
 		break;
	  }
x[3]=x[2];
y[3]=y[2];
y[2]=y[1];
x[2]=x[1];

}

if (log=true)
log=log and (kos(2,3)*kos(4,2)>=0) and (kos(4,2)*kos(5,4)>=0);

if (log=true) 

printf("YES");

else 
printf("NO");

fclose(stdin);
fclose(stdout);

return 0;
}
