#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

typedef long long ui;

ui kos(ui x1,ui y1,ui x2,ui y2)
{
	return (x1*y2-x2*y1);
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	ui n=0;
	scanf("%I64d",&n);
	ui x,y,x1,y1,x2,y2,x3,y3,x4,y4;
	ui sum=0;
	for (int i=1;i<=n;i++)
		{
			x=0;
			y=0;
			x1=0;
			y1=0;
			x2=0;
			y2=0;
			x3=0;
			y3=0;
			x4=0;
			y4=0;
			scanf("%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d",&x,&y,&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
			if ((x1==y1) && (y1==x2) && (x2==x3) && (x3==x4) && (x4==y2) && (y2==y3) && (y3==y4))
				{
					if ((x==x1) && (y==x1))
						sum++;
					continue;
				}
			ui s1=abs(kos(x2-x1,y2-y1,x3-x1,y3-y1))+abs(kos(x3-x1,y3-y1,x4-x1,y4-y1));
			ui s2=abs(kos(x1-x,y1-y,x2-x,y2-y))+abs(kos(x2-x,y2-y,x3-x,y3-y))+abs(kos(x3-x,y3-y,x4-x,y4-y))+abs(kos(x4-x,y4-y,x1-x,y1-y));
			if (s1==s2) sum++;
			
		}
	printf("%d",sum);
	return 0;
}
